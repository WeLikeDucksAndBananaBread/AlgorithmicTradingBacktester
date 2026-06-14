#include <cassert>
#include <iostream>

#include "core/AppInfo.h"

int main() {
    assert(app::applicationName() == QStringLiteral("Algorithmic Trading Backtester"));
    assert(app::windowTitle() == QStringLiteral("Algorithmic Trading Backtester"));

    std::cout << "AppInfo tests passed\n";
    return 0;
}

