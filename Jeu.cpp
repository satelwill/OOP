#include "Jeu.hpp"

#include <chrono>
#include <thread>

Jeu::Jeu(int numRows, int numCols, double initialTime)
    : Now(numRows, numCols), Then(numRows, numCols), time(initialTime) {
}

void Jeu::afficheC() const {
    Now.affiche();
}

void Jeu::AjouteCellule(int rowIndex, int colIndex) {
    Now.AjouteCellule(rowIndex, colIndex);
}

void Jeu::SupprimeCellule(int rowIndex, int colIndex) {
    Now.SupprimeCellule(rowIndex, colIndex);
}

void Jeu::avance() {
    const int totalRows = Now.getRow();
    const int totalCols = Now.getCol();

    for (int rowIndex = 0; rowIndex < totalRows; ++rowIndex) {
        for (int colIndex = 0; colIndex < totalCols; ++colIndex) {
            const int neighborCount = Now.NbVoisins(rowIndex, colIndex);
            const bool isAlive = Now.EstOccupee(rowIndex, colIndex);

            if (!isAlive && neighborCount == 3) {
                Then.AjouteCellule(rowIndex, colIndex);
            } else if (isAlive && (neighborCount == 2 || neighborCount == 3)) {
                Then.AjouteCellule(rowIndex, colIndex);
            } else {
                Then.SupprimeCellule(rowIndex, colIndex);
            }
        }
    }

    //Swap pointers to avoid copying
    std::swap(Now, Then);
}

double Jeu::getTime() const {
    return time;
}

void Jeu::setTime(double newTime) {
    time = newTime;
}

void Jeu::attendre() const {
    std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(time)));
}

// Add these to Jeu.cpp
Grille Jeu::getNow() const {
    return Now;
}

Grille Jeu::getThen() const {
    return Then;
}

