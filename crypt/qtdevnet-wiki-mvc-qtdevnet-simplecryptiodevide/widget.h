// -------------------------------------------------------------------------------------------------
/**
 *  @file
 *  @brief
 *  @author Gerolf Reinwardt
 *  @date   8. march 2011
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

#ifndef WIDGET_H
#define WIDGET_H

// ----- general includes --------------------------------------------------------------------------
#include <QtGui/QWidget>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QLineEdit>
#include <QtGui/QSpinBox>
#include <QtGui/QComboBox>

// ----- local includes ----------------------------------------------------------------------------
// ----- pre defines -------------------------------------------------------------------------------
// ----- class definition --------------------------------------------------------------------------
class SimpleCryptDevice;

// ----- class definition --------------------------------------------------------------------------
/**
 *
 */
class Widget : public QWidget
{
    Q_OBJECT
public:
    // ----- enums ---------------------------------------------------------------------------------

    // ----- XML constants -------------------------------------------------------------------------
    // ----- construction --------------------------------------------------------------------------
    Widget(QWidget *parent = 0);
    ~Widget();

    // ----- operators -----------------------------------------------------------------------------
    // ----- methods -------------------------------------------------------------------------------
    // ----- accessors -----------------------------------------------------------------------------
    // ----- members -------------------------------------------------------------------------------

protected:
    // ----- events --------------------------------------------------------------------------------

protected slots:
    void doCrypt();

private:
    // ----- privat helpers ------------------------------------------------------------------------
    void encryptString(QByteArray& dataArray);
    void decryptString(QByteArray& dataArray);
    void displayRawAndCryptData(QByteArray& dataArray);
    QWidget* createPropsWidget();
    void setCryptProps(SimpleCryptDevice& device);

    // ----- members -------------------------------------------------------------------------------
    QPlainTextEdit* rawText;
    QPlainTextEdit* encryptedText;
    QPlainTextEdit* decryptedText;
    QLineEdit*      encryptKeyEdit;
    QSpinBox*       blockSizeSpin;
    QComboBox*      compressionModeCbo;
    QComboBox*      integrityProtectionCbo;
    // ----- not allowed members -------------------------------------------------------------------
};

#endif // WIDGET_H
