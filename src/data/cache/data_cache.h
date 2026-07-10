#ifndef DATA_CACHE_H
#define DATA_CACHE_H

#include <string>
#include <QObject>

namespace backtester::data {

class DataCache : public QObject {
    Q_OBJECT
public:
    explicit DataCache(QObject *parent = nullptr);
    ~DataCache() override = default;

    // QObject is non-copyable, so explicitly delete copy operations
    DataCache(const DataCache&) = delete;
    auto operator=(const DataCache&) -> DataCache& = delete;
    DataCache(DataCache&&) = delete;
    auto operator=(DataCache&&) -> DataCache& = delete;

    auto saveData(const std::string& symbol, const std::string& data) -> bool;
    auto loadData(const std::string& symbol, std::string& data) -> bool;

private:
    // Implementation details
};

} // namespace backtester::data

#endif // DATA_CACHE_H