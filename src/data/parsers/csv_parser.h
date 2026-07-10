#ifndef CSV_PARSER_H
#define CSV_PARSER_H

#include <string>
#include <vector>

namespace backtester::data {

class CsvParser {
public:
    CsvParser() = default;
    ~CsvParser() = default;

    // Explicitly delete copy and move operations
    CsvParser(const CsvParser&) = delete;
    auto operator=(const CsvParser&) -> CsvParser& = delete;
    CsvParser(CsvParser&&) = delete;
    auto operator=(CsvParser&&) -> CsvParser& = delete;

    // TODO(bence): Add methods for parsing CSV data
    // For example, using rapidcsv, but we'll leave it empty for now
};

} // namespace backtester::data

#endif // CSV_PARSER_H