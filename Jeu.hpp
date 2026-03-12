#ifndef JEU_HPP
#define JEU_HPP

#include "Grille.hpp"

class Jeu {
private:
    Grille Now;
    Grille Then;
    double time;

public:
    Jeu(int numRows, int numCols, double initialTime = 0.0);

    Grille getNow() const;
    Grille getThen() const;
    double getTime() const;

    void setTime(double newTime);
    void setNow(const Grille& newNow);
    void setThen(const Grille& newThen);

    void afficheC() const;
    void AjouteCellule(int rowIndex, int colIndex);
    void SupprimeCellule(int rowIndex, int colIndex);
    void avance();
    void attendre() const; // sleep for 'time' milliseconds
    void ajoute_colonne( int col , int start_row, int end_row);
    void ajoute_ligne( int row , int start_col, int end_col);
};

#endif
