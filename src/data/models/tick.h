#ifndef TICK_H
#define TICK_H

#include <string>

namespace backtester::data {

struct Tick {
    std::string timestamp;
    double price;
    double volume;
};

} // namespace backtester::data

#endif // TICK_H