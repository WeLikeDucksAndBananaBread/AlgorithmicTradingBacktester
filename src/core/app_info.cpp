#include "core/app_info.h"

namespace app {

auto applicationName() -> QString {
    return QStringLiteral("Algorithmic Trading Backtester");
}

auto windowTitle() -> QString {
    return applicationName();
}

} // namespace app

