// -------------------------------------------------------------------------------------------------
/**
 *  @file
 *  @brief
 *  @author Gerolf Reinwardt
 *  @date   09.01.2011
 *
 *  Copyright (c) 2011, Gerolf Reinwardt. All rights reserved.
 *
 *  it's a porting of this class to Qt 4: http://doc.qt.nokia.com/qq/qq12-iodevice.html
 *  The article was presented by the following license: Creative Commons Attribution-Share Alike 2.5 license.
 *
 *  Simplified BSD License
 *
 *  Redistribution and use in source and binary forms, with or without modification, are
 *  permitted provided that the following conditions are met:
 *
 *  1. Redistributions of source code must retain the above copyright notice, this list of
 *     conditions and the following disclaimer.
 *
 *  2. Redistributions in binary form must reproduce the above copyright notice, this list
 *     of conditions and the following disclaimer in the documentation and/or other materials
 *     provided with the distribution.
 *
 *  THIS SOFTWARE IS PROVIDED BY <COPYRIGHT HOLDER> ``AS IS'' AND ANY EXPRESS OR IMPLIED
 *  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 *  FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> OR
 *  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 *  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 *  ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 *  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 *  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *  The views and conclusions contained in the software and documentation are those of the
 *  authors and should not be interpreted as representing official policies, either expressed
 *  or implied, of Gerolf Reinwardt.
 */
// -------------------------------------------------------------------------------------------------

// ----- general includes --------------------------------------------------------------------------
#include <QtCore/QByteArray>

// ----- local includes ----------------------------------------------------------------------------
#include "simplecryptdevice.h"
#include "simplecrypt.h"

// ----- construction ------------------------------------------------------------------------------
SimpleCryptDevice::SimpleCryptDevice(QIODevice* underlyingDevice, QObject* parent) :
    QIODevice(parent),
    m_underlyingDevice(underlyingDevice),
    m_byteBuffer(),
    m_blockSize(256),
    m_crypto()
{

}

SimpleCryptDevice::SimpleCryptDevice(quint64 cryptoKey, QIODevice* underlyingDevice, QObject* parent) :
    QIODevice(parent),
    m_underlyingDevice(underlyingDevice),
    m_byteBuffer(),
    m_blockSize(256),
    m_crypto(cryptoKey)
{
}

SimpleCryptDevice::~SimpleCryptDevice()
{
    close();
}

// ----- operators ---------------------------------------------------------------------------------
// ----- methods -----------------------------------------------------------------------------------
bool SimpleCryptDevice::open(OpenMode mode)
{
    if(isOpen())
    {
        return false;
    }

    if((mode & ReadWrite) == ReadWrite)
        return false;

    OpenMode underlyingOpenMode = mode & ~QIODevice::Text;

    bool underlyingOk = false;
    if (m_underlyingDevice->isOpen())
        underlyingOk = (m_underlyingDevice->openMode() == underlyingOpenMode);
    else
        underlyingOk = m_underlyingDevice->open(underlyingOpenMode);

    if (underlyingOk)
    {
        setOpenMode(mode);
        return true;
    }
    return false;
}

void SimpleCryptDevice::close()
{
    if(isOpen())
    {
        flushEnd();
        m_underlyingDevice->close();
        setOpenMode(NotOpen);
    }
}

bool SimpleCryptDevice::isSequential() const
{
    return true;
}

// ----- accessors ---------------------------------------------------------------------------------
// ----- public slots ------------------------------------------------------------------------------
// ----- protected slots ---------------------------------------------------------------------------
qint64 SimpleCryptDevice::readData(char* data, qint64 maxSize)
{
    int bytesRead = 0;
    if(!m_byteBuffer.isEmpty())
    {
        for(int copyByte = 0; copyByte < qMin(m_byteBuffer.size(), (int)maxSize); ++copyByte, ++bytesRead)
        {
            data[bytesRead] = m_byteBuffer[copyByte];
        }

        m_byteBuffer.remove(0, bytesRead);
    }

    while(m_byteBuffer.isEmpty() && (bytesRead < maxSize) && !m_underlyingDevice->atEnd())
    {
        int sizeOfCypher = 0;
        int bytesReallyRead = m_underlyingDevice->read((char*)&sizeOfCypher, sizeof(sizeOfCypher));

        if(bytesReallyRead != sizeof(sizeOfCypher))
            return -1;

        QByteArray myCypherText;
        myCypherText.resize(sizeOfCypher);
        bytesReallyRead = m_underlyingDevice->read(myCypherText.data(), sizeOfCypher);

        if(bytesReallyRead != bytesRead)
        {
            m_byteBuffer = m_crypto.decryptToByteArray(myCypherText);
            if (m_crypto.lastError() != SimpleCrypt::ErrorNoError)
            {
                // check why we have an error, use the error code from crypto.lastError() for that
                return -1;
            }
            else
            {
                int copyByte = 0;
                for(copyByte = 0; (copyByte < m_byteBuffer.size()) && (bytesRead < (int)maxSize); ++copyByte, ++bytesRead)
                {
                    data[bytesRead] = m_byteBuffer[copyByte];
                }
                m_byteBuffer.remove(0, copyByte);
            }
        }
    }
    return bytesRead;
}

qint64 SimpleCryptDevice::writeData(const char* data, qint64 maxSize)
{
    m_byteBuffer.append(data, (int)maxSize);
    quint64 realBytesWritten = 0;

    // always write blocks of m_blockSize bytes !!!
    while(m_byteBuffer.size() > m_blockSize)
    {
        QByteArray bytesToWrite = m_byteBuffer.left(m_blockSize);
        m_byteBuffer.remove(0, m_blockSize);

        realBytesWritten += writeBlock(bytesToWrite);
    }

    emit encryptedBytesWritten(realBytesWritten);

    return maxSize;
}

// ----- events ------------------------------------------------------------------------------------
// ----- private slots -----------------------------------------------------------------------------
// ----- private helpers ---------------------------------------------------------------------------
void SimpleCryptDevice::flushEnd()
{
    if(openMode() & WriteOnly)
    {
        quint64 realBytesWritten = writeBlock(m_byteBuffer);
        emit encryptedBytesWritten(realBytesWritten);
    }
}

int SimpleCryptDevice::writeBlock(const QByteArray& bytesToWrite)
{
    quint64 realBytesWritten = 0;
    QByteArray myCypherBytes = m_crypto.encryptToByteArray(bytesToWrite); // cypher the bytes
    if (m_crypto.lastError() == SimpleCrypt::ErrorNoError)
    {
        // store the byte block incl. the size
        int sizeOfCypher = myCypherBytes.size();

        realBytesWritten += m_underlyingDevice->write((const char*)&sizeOfCypher, sizeof(sizeOfCypher));
        realBytesWritten += m_underlyingDevice->write(myCypherBytes.data(), sizeOfCypher);
        emit blockWritten();
        return realBytesWritten;
    }
    return 0;
}






