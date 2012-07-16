// -------------------------------------------------------------------------------------------------
/**
 *  @file
 *  @brief
 *  @author Gerolf Reinwardt
 *  @date   09.01.2011
 *
 *  Copyright (c) 2011, Gerolf Reinwardt. All rights reserved.
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
#include <QtCore/QTextStream>
#include <QtCore/QBuffer>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QLabel>

// ----- local includes ----------------------------------------------------------------------------
#include "widget.h"
#include "SimpleCryptDevice.h"
#include "simplecrypt.h"


// ----- construction ------------------------------------------------------------------------------
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton* btn = new QPushButton(tr("en/de crypt via IO"), this);
    rawText = new QPlainTextEdit(this);
    encryptedText = new QPlainTextEdit(this);
    encryptedText->setReadOnly(true);
    QFont ft = encryptedText->font();
    ft.setFamily("Courier New");
    encryptedText->setFont(ft);
    decryptedText = new QPlainTextEdit(this);
    decryptedText->setReadOnly(true);

    QVBoxLayout* myLayout = new QVBoxLayout(this);
    myLayout->addWidget(rawText, 1);
    myLayout->addWidget(btn);
    myLayout->addWidget(encryptedText, 3);
    myLayout->addWidget(decryptedText, 1);
    myLayout->addWidget(createPropsWidget(), 1);

    setLayout(myLayout);

    rawText->setPlainText("Some initialText to en/decrypt.\nChange it and hit the button.");

    connect(btn, SIGNAL(clicked()), this, SLOT(doCrypt()));
}

Widget::~Widget()
{

}

// ----- operators ---------------------------------------------------------------------------------
// ----- methods -----------------------------------------------------------------------------------
// ----- accessors ---------------------------------------------------------------------------------
// ----- public slots ------------------------------------------------------------------------------
// ----- protected slots ---------------------------------------------------------------------------
QString hexToString(const QByteArray& bytes)
{
    QString hexText;

    for(int i = 0; i < bytes.count(); ++i)
    {
        if(!hexText.isEmpty())
            hexText.append(QChar(' '));
        unsigned int n = (uint)(unsigned char)bytes[i];
        hexText.append(QString("%1").arg(n, 2, 16, QChar('0')));
    }

    return hexText;
}

void Widget::doCrypt()
{
    QByteArray dataArray;
    encryptString(dataArray);
    displayRawAndCryptData(dataArray);
    decryptString(dataArray);
}

// ----- events ------------------------------------------------------------------------------------
// ----- private slots -----------------------------------------------------------------------------
// ----- private helpers ---------------------------------------------------------------------------
void Widget::encryptString(QByteArray& dataArray)
{
    QBuffer bufferUsedLikeAFile(&dataArray);
    SimpleCryptDevice deviceFilter(&bufferUsedLikeAFile);
    setCryptProps(deviceFilter);
    deviceFilter.open(QIODevice::WriteOnly);
    QTextStream stream(&deviceFilter);
    QString szText = rawText->toPlainText();
    stream << szText;
}

void Widget::decryptString(QByteArray& dataArray)
{
    QBuffer bufferUsedLikeAFile(&dataArray);
    SimpleCryptDevice deviceFilter(&bufferUsedLikeAFile);
    setCryptProps(deviceFilter);
    deviceFilter.open(QIODevice::ReadOnly);
    QTextStream stream(&deviceFilter);
    QString szText = stream.readAll();
    decryptedText->setPlainText(szText);
}

void Widget::displayRawAndCryptData(QByteArray& dataArray)
{
    QByteArray rawTextArray;
    QBuffer bufferRawTextUsedLikeAFile(&rawTextArray);
    bufferRawTextUsedLikeAFile.open(QIODevice::WriteOnly);
    QTextStream stream(&bufferRawTextUsedLikeAFile);
    QString szText = rawText->toPlainText();
    stream << szText;
    bufferRawTextUsedLikeAFile.close();

    QString text = tr("Text stream in bytes:  (len: %1): \n%2\n")
                        .arg(rawTextArray.size(), 4, 10)
                        .arg(hexToString(rawTextArray));
    text.append(   tr("Crypt stream in bytes: (len: %1)\n%2")
                        .arg(dataArray.size(), 4, 10)
                        .arg(hexToString(dataArray)));

    encryptedText->setPlainText(text);
}

QWidget* Widget::createPropsWidget()
{
    QGroupBox* props = new QGroupBox(tr("Properties"), this);

    QGridLayout* pLayout = new QGridLayout(props);
    props->setLayout(pLayout);

    int row = 0;
    pLayout->addWidget(new QLabel(tr("encrypt key (64 bit): "), props), row, 0);
    encryptKeyEdit = new QLineEdit(props);
    pLayout->addWidget(encryptKeyEdit, row, 1);

    QRegExp reg("^[0-9a-fA-F]{0,16}$");
    QRegExpValidator* valid = new QRegExpValidator(reg, this);
    encryptKeyEdit->setValidator(valid);
    encryptKeyEdit->setText(QLatin1String("0c2ad4a4acb9f023"));

    pLayout->addWidget(new QLabel(tr("Block size (bytes): "), props), ++row, 0);
    blockSizeSpin = new QSpinBox(props);
    blockSizeSpin->setRange(1, 1024*1024);
    blockSizeSpin->setValue(256);
    pLayout->addWidget(blockSizeSpin, row, 1);


    pLayout->addWidget(new QLabel(tr("Compression Mode: "), props), ++row, 0);
    compressionModeCbo = new QComboBox(props);
    pLayout->addWidget(compressionModeCbo, row, 1);
    compressionModeCbo->addItem(tr("CompressionAuto"), SimpleCrypt::CompressionAuto);
    compressionModeCbo->addItem(tr("CompressionAlways"), SimpleCrypt::CompressionAlways);
    compressionModeCbo->addItem(tr("CompressionNever"), SimpleCrypt::CompressionNever);
    compressionModeCbo->setCurrentIndex(compressionModeCbo->findText(tr("CompressionAlways")));

    pLayout->addWidget(new QLabel(tr("Integrity Protection: "), props), ++row, 0);
    integrityProtectionCbo = new QComboBox(props);
    pLayout->addWidget(integrityProtectionCbo, row, 1);
    integrityProtectionCbo->addItem(tr("ProtectionNone"), SimpleCrypt::ProtectionNone);
    integrityProtectionCbo->addItem(tr("ProtectionChecksum"), SimpleCrypt::ProtectionChecksum);
    integrityProtectionCbo->addItem(tr("ProtectionHash"), SimpleCrypt::ProtectionHash);
    integrityProtectionCbo->setCurrentIndex(integrityProtectionCbo->findText(tr("ProtectionHash")));

    return props;
}

void Widget::setCryptProps(SimpleCryptDevice& device)
{
    device.setBlockSize(blockSizeSpin->value());
    quint64 key = encryptKeyEdit->text().toULongLong(0, 16);
    device.setKey(key);
    device.setCompressionMode((SimpleCrypt::CompressionMode) compressionModeCbo->itemData(compressionModeCbo->currentIndex()).toInt());
    device.setIntegrityProtectionMode((SimpleCrypt::IntegrityProtectionMode) integrityProtectionCbo->itemData(integrityProtectionCbo->currentIndex()).toInt());
}

