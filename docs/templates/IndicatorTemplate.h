#ifndef INDICATORTEMPLATE_H
#define INDICATORTEMPLATE_H

#include <vector>

#include "data/models/bar.h"  // For the Bar struct

class IndicatorTemplate {
 public:
  // Constructor: period is the lookback period for the indicator
  explicit IndicatorTemplate(int period);

  // The main calculation method for the indicator.
  // It takes a vector of bars and returns the calculated indicator values.
  auto calculate(const std::vector<backtester::data::Bar>& data) const
      -> std::vector<double>;

 private:
  int period_;  // The lookback period
};

#endif  // INDICATORTEMPLATE_H
