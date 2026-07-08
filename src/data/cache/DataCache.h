#ifndef DATA_CACHE_H
#define DATA_CACHE_H

#include <string>
#include <QObject>

namespace backtester {
namespace data {

class DataCache : public QObject {
    Q_OBJECT
public:
    explicit DataCache(QObject *parent = nullptr);
    ~DataCache();
    
    bool saveData(const std::string& symbol, const std::string& data);
    bool loadData(const std::string& symbol, std::string& data);
    
private:
    // Implementation details
};

} // namespace data
} // namespace backtester

#endif // DATA_CACHE_H