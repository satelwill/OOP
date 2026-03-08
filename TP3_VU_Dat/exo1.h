#ifndef EXO1_H
#define EXO1_H

#include <iostream>
#include<vector>


class Grille 
{
    private:
    int m,n; 
    std::vector<std::vector<bool>> cellules;

    public:
    Grille(int m=0, int n=0);
    //~Grille(); 
    void AjouteCellule(int m, int n);
    void SupprimeCellule(int m, int n);
    void affiche();
    bool EstOccupee(int i, int j);
    int NbVoisins(int i, int j);
    int getCol();
    int getRow();
    
};
class Jeu 
{ //using 2 grille: now and then , update then now=then 
    private:
    Grille Now;
    Grille Then;
    
    public:
    Jeu(int m, int n); // Init 2 identical grilles
    void afficheC();
    void AjouteCellule(int i, int j);
    void SupprimeCellule(int i ,int j);
    void avance(); 

};

#endif 