#-------------------------------------------------
#  @file
#  @brief
#  @author Gerolf Reinwardt
#  @date   8. march 2011
#
#  Copyright (c) 2011, Gerolf Reinwardt. All rights reserved.
#
#  Simplified BSD License
#
#  Redistribution and use in source and binary forms, with or without modification, are
#  permitted provided that the following conditions are met:
#
#  1. Redistributions of source code must retain the above copyright notice, this list of
#     conditions and the following disclaimer.
#
#  2. Redistributions in binary form must reproduce the above copyright notice, this list
#     of conditions and the following disclaimer in the documentation and/or other materials
#     provided with the distribution.
#
#  THIS SOFTWARE IS PROVIDED BY <COPYRIGHT HOLDER> ``AS IS'' AND ANY EXPRESS OR IMPLIED
#  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
#  FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> OR
#  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
#  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
#  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
#  ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
#  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
#  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
#  The views and conclusions contained in the software and documentation are those of the
#  authors and should not be interpreted as representing official policies, either expressed
#  or implied, of Gerolf Reinwardt.
#-------------------------------------------------

QT       += core gui

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

TARGET = SimpleCryptIoDevide
TEMPLATE = app


SOURCES += main.cpp\
           widget.cpp \
           simplecryptdevice.cpp \
           simplecrypt.cpp

HEADERS  += widget.h \
            simplecryptdevice.h \
            simplecrypt.h

OTHER_FILES = license.txt

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

VERSION = 01.00.00

# change the nama of the binary, if it is build in debug mode
CONFIG(debug, debug|release) {
     mac: TARGET = $$join(TARGET,,,_debug)
     win32: TARGET = $$join(TARGET,,,d)
}

#define the directory, where the binary is placed
RCC_DIR     = ./tmp
UI_DIR     = ./tmp

CONFIG(debug, debug|release) {
    DESTDIR     = ../debug
    OBJECTS_DIR = ./tmp/debug
    MOC_DIR     = ./tmp/moc/debug
}
else {
    DESTDIR     = ../release
    OBJECTS_DIR = ./tmp/release
    MOC_DIR     = ./tmp/moc/release
}
