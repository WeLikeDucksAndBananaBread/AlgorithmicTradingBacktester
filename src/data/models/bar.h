#ifndef BAR_H
#define BAR_H

#include <string>

namespace backtester {
namespace data {

struct Bar {
    std::string timestamp;
    double open;
    double high;
    double low;
    double close;
    double volume;
};

} // namespace data
} // namespace backtester

#endif // BAR_H