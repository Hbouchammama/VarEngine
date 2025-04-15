#include "DataLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::map<std::string, std::vector<double>> DataLoader::loadHistoricalPrices(const std::string& filePath) {
    std::map<std::string, std::vector<double>> prices;
    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << filePath << std::endl;
        return prices;
    }

    
    std::string line;
    std::vector<std::string> assetNames;

    // Lire l'en-tête du fichier (les noms des actifs)
    if (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string asset;
        while (std::getline(ss, asset, ',')) {
            assetNames.push_back(asset);
            prices[asset] = {};  // Initialiser la structure de stockage
        }
    }

    // Lire les prix ligne par ligne
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string priceStr;
        size_t i = 0;

        while (std::getline(ss, priceStr, ',')) {
            try {
                double price = std::stod(priceStr);
                prices[assetNames[i]].push_back(price);
            } catch (const std::exception& e) {
                std::cerr << "Erreur de conversion : " << e.what() << std::endl;
            }
            i++;
        }
    }

    file.close();
    return prices;
}