#include "core/AppInfo.h"

namespace app {

QString applicationName() {
    return QStringLiteral("Algorithmic Trading Backtester");
}

QString windowTitle() {
    return applicationName();
}

} // namespace app

