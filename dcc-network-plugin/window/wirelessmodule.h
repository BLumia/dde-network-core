/*
* Copyright (C) 2021 ~ 2023 Deepin Technology Co., Ltd.
*
* Author:     caixiangrong <caixiangrong@uniontech.com>
*
* Maintainer: caixiangrong <caixiangrong@uniontech.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef WIRELESSMODULE_H
#define WIRELESSMODULE_H

#include "interface/pagemodule.h"

#include <dtkwidget_global.h>

DWIDGET_BEGIN_NAMESPACE
class DListView;
DWIDGET_END_NAMESPACE

namespace dde {
namespace network {
class AccessPoints;
class WirelessDevice;
}
}

class WirelessModule : public DCC_NAMESPACE::PageModule
{
    Q_OBJECT
public:
    explicit WirelessModule(dde::network::WirelessDevice *dev, QObject *parent = nullptr);

private Q_SLOTS:
    void onNetworkAdapterChanged(bool checked);
    void onApWidgetEditRequested(dde::network::AccessPoints *ap, QWidget *parent);
    void initWirelessList(DTK_WIDGET_NAMESPACE::DListView *lvAP);
    void onNameChanged(const QString &name);

private:
    dde::network::WirelessDevice *m_device;
};

#endif // WIRELESSMODULE_H
