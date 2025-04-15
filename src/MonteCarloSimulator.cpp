// MonteCarloSimulator.cpp
#include "MonteCarloSimulator.h"
#include "Utils.h"
#include <random>
#include <algorithm>
#include <vector>
#include <stdexcept>

double MonteCarloSimulator::simulateVaR(const std::vector<double>& portfolioReturns, int numSimulations, double confidenceLevel) {
    if (confidenceLevel <= 0 || confidenceLevel >= 1) {
        throw std::invalid_argument("Le niveau de confiance doit être entre 0 et 1.");
    }
    if (numSimulations <= 0) {
        throw std::invalid_argument("Le nombre de simulations doit être supérieur à 0.");
    }

    // Calcul de la moyenne et de l'écart-type des rendements historiques
    double mean = Utils::calculateMean(portfolioReturns);
    double stdDev = Utils::calculateStandardDeviation(portfolioReturns);

    // Générateur de nombres aléatoires suivant une distribution normale
    std::random_device rd;
    std::mt19937 generator(rd());
    std::normal_distribution<double> distribution(mean, stdDev);

    // Génération des rendements simulés
    std::vector<double> simulatedReturns(numSimulations);
    for (int i = 0; i < numSimulations; ++i) {
        simulatedReturns[i] = distribution(generator);
    }

    // Tri des rendements simulés pour obtenir le quantile
    std::sort(simulatedReturns.begin(), simulatedReturns.end());

    // Index du quantile (1 - alpha)
    int varIndex = static_cast<int>((1 - confidenceLevel) * numSimulations);

    // VaR Monte Carlo (quantile correspondant)
    return simulatedReturns[varIndex];
}