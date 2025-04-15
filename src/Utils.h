#ifndef UTILS_H
#define UTILS_H

#include <vector>

class Utils {
public:
    // Calcule la moyenne des éléments d'un vecteur
    static double calculateMean(const std::vector<double>& data);

    // Calcule l'écart-type des éléments d'un vecteur
    static double calculateStandardDeviation(const std::vector<double>& data);

    // Retourne la valeur Z correspondant à un niveau de confiance
    static double getZValue(double confidenceLevel);
};

#endif // UTILS_H