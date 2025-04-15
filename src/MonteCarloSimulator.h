#ifndef MONTECARLOSIMULATOR_H
#define MONTECARLOSIMULATOR_H

#include <vector>

class MonteCarloSimulator {
public:
    // Simule la VaR via la méthode de Monte Carlo
    static double simulateVaR(const std::vector<double>& portfolioReturns, int numSimulations, double confidenceLevel);
};

#endif // MONTECARLOSIMULATOR_H