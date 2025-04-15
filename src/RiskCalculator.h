#ifndef RISK_CALCULATOR_H
#define RISK_CALCULATOR_H


#include <vector>
#include <map>
#include <string>
#include "Utils.h"
class RiskCalculator {
public:
    static std::map<std::string, std::vector<double>> computeReturns(const std::map<std::string, std::vector<double>>& prices);
    static double historicalVaR(const std::vector<double>& returns, double confidenceLevel);
    static double parametricVaR(const std::vector<double>& portfolioReturns, double confidenceLevel);
};

#endif // RISK_CALCULATOR_H