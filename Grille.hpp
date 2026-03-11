#ifndef GRILLE_HPP
#define GRILLE_HPP

#include <vector>

class Grille {
private:
    int rowCount;
    int colCount;
    std::vector<std::vector<bool>> cellules;

public:
    Grille(int numRows = 0, int numCols = 0);

    void AjouteCellule(int rowIndex, int colIndex);
    void SupprimeCellule(int rowIndex, int colIndex);

    void affiche() const;
    bool EstOccupee(int rowIndex, int colIndex) const;
    int NbVoisins(int rowIndex, int colIndex) const;

    int getRow() const;
    int getCol() const;
};

#endif
