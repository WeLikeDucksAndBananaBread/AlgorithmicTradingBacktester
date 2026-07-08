#ifndef TICK_H
#define TICK_H

#include <string>

namespace backtester {
namespace data {

struct Tick {
    std::string timestamp;
    double price;
    double volume;
};

} // namespace data
} // namespace backtester

#endif // TICK_H