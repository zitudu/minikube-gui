/*
Copyright 2023 The Kubernetes Authors All rights reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include "fonts.h"

#include <QDebug>
#include <QFontDatabase>
#include <QToolTip>

QFont Fonts::fontAwesome;

void Fonts::initFonts()
{
    loadFontAwesome();
    setToolTipFont();
}

void Fonts::loadFontAwesome()
{
    if (QFontDatabase::addApplicationFont(":/fonts/FontAwesome.otf") < 0)
        qWarning() << "FontAwesome cannot be loaded!";
    fontAwesome.setFamily("FontAwesome");
    fontAwesome.setPixelSize(20);
}

void Fonts::setToolTipFont()
{
    QFont tooltipFont = QToolTip::font();
    tooltipFont.setPointSize(20);
    QToolTip::setFont(tooltipFont);
}

void Fonts::setFontAwesome(QWidget *wid)
{
    wid->setFont(fontAwesome);
}
