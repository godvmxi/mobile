// -------------------------------------------------------------------------------------------------
/**
 *  @file
 *  @brief
 *  @author Gerolf Reinwardt
 *  @date   8. march 2011
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

#ifndef CRYPTDEVICE_H
#define CRYPTDEVICE_H

// ----- general includes --------------------------------------------------------------------------
#include <QtCore/QIODevice>
#include <QtCore/QByteArray>

// ----- local includes ----------------------------------------------------------------------------
#include "SimpleCrypt.h"

// ----- pre defines -------------------------------------------------------------------------------

// ----- class definition --------------------------------------------------------------------------
/**
 *  @short Simple example of a more complex custom IO device that en/decrypts on the fly.
 *         The encryption algorthim and class (SimpleCrypt) was written by Andre Somers
 *
 *  @warning The encryption provided by this class is NOT strong encryption. It may
 *           help to shield things from curious eyes, but it will NOT stand up to someone
 *           determined to break the encryption. Don't say you were not warned.
 *
 *  This class encrypts / decrypts data on the fly by using the SimpleCrypt class. The
 *  encrypted data is written to a given underlying device, which is responsible for storing
 *  the data or sending the data via the net or whatever. Each standard QIODevice derived
 *  class may be used as underlying device.
 *
 *  example usage for encryption:
 *
 *  @code
    void encryptString(QByteArray& targetArray, QString textToStore)
    {
        QBuffer bufferUsedLikeAFile(&dataArray);
        SimpleCryptDevice deviceFilter(Q_UINT64_C(0x0c2ad4a4acb9f023), &bufferUsedLikeAFile);
        deviceFilter.open(QIODevice::WriteOnly);
        QTextStream stream(&deviceFilter);
        stream << textToStore;
    }
    @endcode
 *
 *  example usage for decryption:
 *
 *  @code
    QString decryptString(QByteArray& sourceArray)
    {
        QBuffer bufferUsedLikeAFile(&dataArray);
        SimpleCryptDevice deviceFilter(Q_UINT64_C(0x0c2ad4a4acb9f023), &bufferUsedLikeAFile);
        deviceFilter.open(QIODevice::ReadOnly);
        QTextStream stream(&deviceFilter);
        QString text = stream.readAll();
        return text;
    }
    @endcode
 *
 */
class SimpleCryptDevice : public QIODevice
{
    Q_OBJECT
public:
    // ----- enums ---------------------------------------------------------------------------------
    // ----- construction --------------------------------------------------------------------------
    /**
     *  Constructor.
     *
     *  Constructs a SimpleCryptDevice instance and initializes it with the given  @arg underlyingDevice.
     *  The crypt key can be set by setKey.
     *
     *  @param underlyingDevice device that is used to store the data
     *  @param parent           parent object, see Qt documentation
     */
    SimpleCryptDevice(QIODevice* underlyingDevice, QObject* parent = 0);

    /**
     *  Constructor.
     *
     *  Constructs a SimpleCryptDevice instance and initializes it with the given @arg key and
     *  @arg underlyingDevice.
     *
     *  @param cryptoKey        crypto key, used by the SimpleCrypt class
     *  @param underlyingDevice device that is used to store the data
     *  @param parent           parent object, see Qt documentation
     */
    SimpleCryptDevice(quint64 cryptoKey, QIODevice* underlyingDevice, QObject* parent = 0);

    /**
     *  destructor
     */
    ~SimpleCryptDevice();

    // ----- operators -----------------------------------------------------------------------------
    // ----- methods -------------------------------------------------------------------------------
    /**
     *  Opens the device in read or write mode. ReadWrite is not supported.
     */
    virtual bool open(OpenMode mode);

    /**
     *  Overwritten method to close the device.
     */
    virtual void close();

    /**
     * Returns true as it is a sequential device.
     */
    virtual bool isSequential() const;

    // ----- accessors -----------------------------------------------------------------------------

    /**
     *  Sets the block size. The block size is the amount of data in bytes that is encrypted as
     *  one block of data.
     */
    void setBlockSize(qint32 blockSize) {m_blockSize = blockSize; }

    /**
     *  returns the currently used block size.
     */
    qint32 blockSize() const {return m_blockSize; }


    // ----- crypto parameters ---------------------------------------------------------------------
    /**
     *  (Re-) initializes the key with the given @arg key.
     */
    void setKey(quint64 key) {m_crypto.setKey(key);}

    /**
     *  Sets the compression mode to use when encrypting data. The default mode is Auto.
     *
     *  Note that decryption is not influenced by this mode, as the decryption recognizes
     *  what mode was used when encrypting.
     */
    void setCompressionMode(SimpleCrypt::CompressionMode mode) {m_crypto.setCompressionMode(mode);}

    /**
     *  Returns the CompressionMode that is currently in use.
     */
    SimpleCrypt::CompressionMode compressionMode() const {return m_crypto.compressionMode();}

    /**
     *  Sets the integrity mode to use when encrypting data. The default mode is Checksum.
     *
     *  Note that decryption is not influenced by this mode, as the decryption recognizes
     *  what mode was used when encrypting.
     */
    void setIntegrityProtectionMode(SimpleCrypt::IntegrityProtectionMode mode) {m_crypto.setIntegrityProtectionMode(mode);}

    /**
     *  Returns the IntegrityProtectionMode that is currently in use.
     */
    SimpleCrypt::IntegrityProtectionMode integrityProtectionMode() const {return m_crypto.integrityProtectionMode();}

    /**
     * Returns the last error that occurred.
     */
    int lastCryptoError() const {return m_crypto.lastError();}

signals:
    /**
     *  This signal is emitted when SimpleCryptDevice writes its encrypted data to the underlying device.
     *  The @arg written parameter contains the number of bytes that were successfully written.
     *
     *  See also QIODevice::bytesWritten().
     */
    void encryptedBytesWritten(qint64 written);

    /**
     *  This signal is emitted when SimpleCryptDevice writes a block of raw data to the underlying device.
     */
    void blockWritten();

protected:
    // ----- overwritten methods -------------------------------------------------------------------
    /**
     *  reimplemented to read data from the device.
     */
    virtual qint64 readData(char* data, qint64 maxSize);

    /**
     *  reimplemented to store data in the device.
     */
    virtual qint64 writeData(const char* data, qint64 maxSize);

private:
    // ----- privat helpers ------------------------------------------------------------------------
    /**
     *  flushes the content of the current m_byteBuffer to the underlying device.
     *  This is needed to store the unwritten buffer at close().
     */
    void flushEnd();

    /**
     *  writes the given block of raw data to the device. while writing, the data is encrypted.
     */
    int writeBlock(const QByteArray& bytesToWrite);

    // ----- members -------------------------------------------------------------------------------
    QIODevice*  m_underlyingDevice; /**< device used to write data to / read data from */
    QByteArray  m_byteBuffer;       /**< internal buffer used, as data is written block wise */
    qint32      m_blockSize;       /**< size of the internal buffer used */
    SimpleCrypt m_crypto;           /**< crypto algorithm used for reading / writing data */


    // ----- not allowed members -------------------------------------------------------------------
    Q_DISABLE_COPY(SimpleCryptDevice)
};

#endif // CRYPTDEVICE_H
