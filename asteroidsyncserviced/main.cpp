/*
 * Copyright (C) 2018 - Florent Revest <revestflo@gmail.com>
 *               2016 - Andrew Branson <andrew.branson@jollamobile.com>
 *                      Ruslan N. Marchenko <me@ruff.mobi>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <QCoreApplication>
#include "dbusinterface.h"
#include "watchesmanager.h"

#ifdef UBUNTU_TOUCH_PLATFORM
#include "platforms/ubuntutouch/ubuntuplatform.h"
#elif SAILFISHOS_PLATFORM
#include "platforms/sailfishos/sailfishplatform.h"
#else
#error no platform being selected
#endif

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    WatchesManager watchesManager;
#ifdef UBUNTU_TOUCH_PLATFORM
    UbuntuPlatform platform(&watchesManager);
#elif SAILFISHOS_PLATFORM
    SailfishPlatform platform(&watchesManager);
#endif
    DBusInterface dbusInterface(&watchesManager);

    return a.exec();
}
