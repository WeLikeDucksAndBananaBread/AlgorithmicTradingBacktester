#ifndef BAR_H
#define BAR_H

#include <string>

namespace backtester::data {

struct Bar {
    std::string timestamp;
    double open;
    double high;
    double low;
    double close;
    double volume;
};

} // namespace backtester::data

#endif // BAR_H