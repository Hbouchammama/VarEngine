# 📉 VarEngine - Calcul de la Value at Risk (VaR)

## 🧠 Description

**VarEngine** est un moteur de calcul de la Value at Risk (VaR) en C++.  
Il permet de mesurer le risque de perte potentielle d’un portefeuille financier en utilisant trois approches classiques :

- **VaR Historique**
- **VaR Paramétrique (Variance-Covariance)**
- **VaR Monte Carlo**

Ce projet est destiné à des fins éducatives et de modélisation du risque de marché.

## 📁 Structure du projet

```
VarEngine/
├── src/                      # Code source principal
│   ├── main.cpp
│   ├── RiskCalculator.h
│   ├── RiskCalculator.cpp
│   ├── MonteCarloSimulator.h
│   ├── MonteCarloSimulator.cpp
│   ├── DataLoader.h
│   ├── DataLoader.cpp
│   ├── Utils.h
│   ├── Utils.cpp
│
├── data/                     # Données historiques (CSV)
│   └── historical_prices.csv
│
├── bin/                      # Fichiers exécutables générés
│
├── Makefile                  # Script de compilation
├── README.md                 # Ce fichier
``` la compilation ├── README.md # Ce fichier

## ⚙️ Compilation

Assurez-vous d’avoir installé `g++` et `make`. Puis, depuis la racine du projet :

```bash

mingw32-make          
mingw32-make clean   