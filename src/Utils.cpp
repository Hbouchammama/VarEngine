#include "Utils.h"
#include <cmath>
#include <stdexcept>
#include <vector>


// Calcule la moyenne des éléments d'un vecteur
double Utils::calculateMean(const std::vector<double>& data) {
    double sum = 0.0;
    for (double value : data) {
        sum += value;
    }
    return sum / data.size();

} 

// Calcule l'écart-type des éléments d'un vecteur
double Utils::calculateStandardDeviation(const std::vector<double>& data) {
    double mean = calculateMean(data);
    double variance = 0.0;
    for (double value : data) {
        variance += (value - mean) * (value - mean);
    }
    return std::sqrt(variance / data.size());
}


double Utils::getZValue(double confidenceLevel) {
    if (confidenceLevel == 0.95) {
        return 1.645;  // Z pour 95% de confiance
    } else if (confidenceLevel == 0.99) {
        return 2.33;   // Z pour 99% de confiance
    } else if (confidenceLevel == 0.90) {
        return 1.28;   // Z pour 90% de confiance
    } else {
        throw std::invalid_argument("Niveau de confiance non supporté.");
    }
}