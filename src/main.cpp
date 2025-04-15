#include <iostream>
#include <vector>
#include <iostream>
#include <vector>
#include "RiskCalculator.h"
#include "DataLoader.h"
#include "MonteCarloSimulator.h"
#include "Utils.h"

int main() {
    // Charger les données historiques à partir du fichier CSV
    std::string dataFilePath = "../data/historical_prices.csv";  // Spécifiez le chemin vers votre fichier CSV

    
    // Charger les données historiques (prix) depuis le fichier CSV
    std::map<std::string, std::vector<double>> historicalPrices = DataLoader::loadHistoricalPrices(dataFilePath);

    // Assurez-vous qu'il y a des données dans le fichier
    if (historicalPrices.empty()) {
        std::cerr << "Erreur : Aucune donnée chargée depuis le fichier CSV." << std::endl;
        return 1;
    }

    // Calculer les rendements pour chaque actif
    std::map<std::string, std::vector<double>> portfolioReturns = RiskCalculator::computeReturns(historicalPrices);
    
    // Exemple avec un seul actif, ici "Asset1", vous pouvez adapter pour d'autres actifs
    if (portfolioReturns.find("Asset1") == portfolioReturns.end()) {
        std::cerr << "Erreur : Actif 'Asset1' non trouvé dans les données." << std::endl;
        return 1;
    }

    std::vector<double> historicalReturns = portfolioReturns["Asset1"];
    double confidenceLevel = 0.95;  // Niveau de confiance 95%
    int numSimulations = 10000;  // Nombre de simulations Monte Carlo

    try { 
        
        // Calcul de la VaR Historique
        double varHistorical = RiskCalculator::historicalVaR(historicalReturns, confidenceLevel);
        std::cout << "VaR Historique : " << varHistorical << " EUR\n";

        // Calcul de la VaR Paramétrique
        double varParametric = RiskCalculator::parametricVaR(historicalReturns, confidenceLevel);
        std::cout << "VaR Paramétrique : " << varParametric << " EUR\n";

        // Calcul de la VaR Monte Carlo
        double varMonteCarlo = MonteCarloSimulator::simulateVaR(historicalReturns, numSimulations, confidenceLevel);
        std::cout << "VaR Monte Carlo : " << varMonteCarlo << " EUR\n";

    } catch (const std::invalid_argument& e) {
        std::cout << "Erreur : " << e.what() << std::endl;
    }

    return 0;
}