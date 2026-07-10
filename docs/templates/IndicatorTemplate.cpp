#include "IndicatorTemplate.h"

IndicatorTemplate::IndicatorTemplate(int period) : period_(period) {
  // Any initialization for the indicator can be done here.
}

auto IndicatorTemplate::calculate(
    const std::vector<backtester::data::Bar>& data) const
    -> std::vector<double> {
  std::vector<double> indicator_values;
  if (data.size() < static_cast<size_t>(period_)) {
    // Not enough data to calculate the indicator, return empty vector
    return indicator_values;
  }

  // Loop through the data and calculate the indicator value at each point
  // This example calculates a Simple Moving Average (SMA)
  for (size_t i = period_ - 1; i < data.size(); ++i) {
    double sum = 0.0;
    for (int j = 0; j < period_; ++j) {
      sum += data[i - j].close;
    }
    double indicator_value = sum / period_;
    indicator_values.push_back(indicator_value);
  }

  return indicator_values;
}
