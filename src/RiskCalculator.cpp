#include "RiskCalculator.h"
#include "Utils.h"
#include <cmath>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <map>

std::map<std::string, std::vector<double>> RiskCalculator::computeReturns(const std::map<std::string, std::vector<double>>& prices) {
    std::map<std::string, std::vector<double>> returns;

    for (const auto& pair : prices) {
        const std::string& asset = pair.first;
        const std::vector<double>& priceList = pair.second;
        std::vector<double> returnList;

        for (size_t i = 1; i < priceList.size(); ++i) {
            double logReturn = log(priceList[i] / priceList[i - 1]);
            returnList.push_back(logReturn);
        }

        returns[asset] = returnList;
    }

    return returns;
}


double RiskCalculator::historicalVaR(const std::vector<double>& returns, double confidenceLevel) {
    if (returns.empty()) {
        std::cerr << "Erreur : Liste de rendements vide pour le calcul de la VaR" << std::endl;
        return 0.0;
    }

    std::vector<double> sortedReturns = returns;
    std::sort(sortedReturns.begin(), sortedReturns.end());

    size_t index = static_cast<size_t>((1.0 - confidenceLevel) * sortedReturns.size());
    
    return sortedReturns[index];  // Valeur négative car la VaR représente une perte

}
 double RiskCalculator::parametricVaR(const std::vector<double>& portfolioReturns, double confidenceLevel) {
    if (confidenceLevel <= 0 || confidenceLevel >= 1) {
        throw std::invalid_argument("Le niveau de confiance doit être entre 0 et 1.");
    }

    // Utiliser les fonctions utilitaires pour calculer la moyenne et l'écart-type
    double mean = Utils::calculateMean(portfolioReturns);
    double stdDev = Utils::calculateStandardDeviation(portfolioReturns);

    // Calcul de la valeur critique Z pour le niveau de confiance donné
    double Z = Utils::getZValue(confidenceLevel);

    
    // Calcul de la VaR paramétrique
    return mean - Z * stdDev;
}
