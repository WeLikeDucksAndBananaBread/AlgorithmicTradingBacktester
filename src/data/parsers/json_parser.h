#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include <string>
#include <vector>

namespace backtester::data {

class JsonParser {
public:
    JsonParser() = default;
    ~JsonParser() = default;

    // Explicitly delete copy and move operations
    JsonParser(const JsonParser&) = delete;
    auto operator=(const JsonParser&) -> JsonParser& = delete;
    JsonParser(JsonParser&&) = delete;
    auto operator=(JsonParser&&) -> JsonParser& = delete;

    // TODO(bence): Add methods for parsing JSON data
};

} // namespace backtester::data

#endif // JSON_PARSER_H