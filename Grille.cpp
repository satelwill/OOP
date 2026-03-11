#include "Grille.hpp"
#include <iostream>

Grille::Grille(int numRows, int numCols)
    : rowCount(numRows), colCount(numCols), cellules(numRows, std::vector<bool>(numCols, false)) {
}

void Grille::AjouteCellule(int rowIndex, int colIndex) {
    if (rowIndex >= 0 && rowIndex < rowCount && colIndex >= 0 && colIndex < colCount) {
        cellules[rowIndex][colIndex] = true;
    } else {
        std::cerr << "Index out of bound\n";
    }
}

void Grille::SupprimeCellule(int rowIndex, int colIndex) {
    if (rowIndex >= 0 && rowIndex < rowCount && colIndex >= 0 && colIndex < colCount) {
        cellules[rowIndex][colIndex] = false;
    } else {
        std::cerr << "Index out of bound\n";
    }
}

int Grille::getRow() const {
    return rowCount;
}

int Grille::getCol() const {
    return colCount;
}

void Grille::affiche() const {
    for (int row = 0; row < rowCount; ++row) {
        for (int col = 0; col < colCount; ++col) {
            std::cout << (cellules[row][col] ? "X" : "O");
        }
        std::cout << "\n";
    }
}

bool Grille::EstOccupee(int rowIndex, int colIndex) const {
    if (rowIndex >= 0 && rowIndex < rowCount && colIndex >= 0 && colIndex < colCount) {
        return cellules[rowIndex][colIndex];
    }

    std::cerr << "Index out of bound\n";
    return false;
}

int Grille::NbVoisins(int rowIndex, int colIndex) const {
    int neighborCount = 0;

    for (int neighborRow = rowIndex - 1; neighborRow <= rowIndex + 1; ++neighborRow) {
        for (int neighborCol = colIndex - 1; neighborCol <= colIndex + 1; ++neighborCol) {
            if (neighborRow == rowIndex && neighborCol == colIndex) {
                continue;
            }

            if (neighborRow >= 0 && neighborRow < rowCount && neighborCol >= 0 && neighborCol < colCount) {
                if (cellules[neighborRow][neighborCol]) {
                    ++neighborCount;
                }
            }
        }
    }

    return neighborCount;
}
