#ifndef DATALOADER_H
#define DATALOADER_H

#include <map>
#include <vector>
#include <string>

class DataLoader {
public:
    static std::map<std::string, std::vector<double>> loadHistoricalPrices(const std::string& filePath);
};

#endif
