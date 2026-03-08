#include"exo1.h"
#include<iostream>

Grille::Grille(int m, int n) : m(m), n(n), cellules(m, std::vector<bool>(n, false)) {
}
void Grille::AjouteCellule(int m , int n){
    if(m>=0 && m<this->m && n>=0 && n<this->n ){
        cellules[m][n]=true;
    }
    else{
        std::cerr <<"Index out of bound";
    }

}
void Grille::SupprimeCellule(int m , int n){
    if(m>=0 && m<this->m && n>=0 && n<this->n ){
        cellules[m][n]=false;
    }
    else{
        std::cerr <<"Index out of bound";
    }

}
int Grille::getRow(){
    return m;
}

int Grille::getCol(){
    return n;
}


void Grille::affiche(){
    m=this->m;
    n=this->n;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if(cellules[i][j]==true){
                std:: cout<<"X";
            }
            else{
                std:: cout << "O";
            }
        }
        std:: cout<<"\n";
    }
}

bool Grille::EstOccupee(int i, int j){
    if(i>=0 && i<this->m && j>=0 && j<this->n ){
         return this->cellules[i][j];
    }
    else{
        std::cerr <<"Index out of bound";
        return -1;
    }
    //return cellules[i][j];
}

int Grille::NbVoisins(int i, int j){
    
    m= this->m;
    n= this->n;
    int count=0;

    for (int t =i-1;t<i+2;t++){
        for (int k=j-1;k<j+2;k++){
            if (t==i&&k==j){
                continue;
            }
            if(t>=0 && t<this->m && k>=0 && k<this->n ){
                if (cellules[t][k]){
                    count++;
                }
            }

            
        }
    }
    return count;

}


Jeu::Jeu(int m, int n){
    Grille g1(m,n);
    Grille g2(m,n);
    this->Now=g1;
    this->Then=g2;
}


void Jeu::afficheC(){
    Now.affiche();
}
void Jeu::AjouteCellule(int i, int j){
    Now.AjouteCellule(i,j);
}

void Jeu::SupprimeCellule(int i, int j){
    Now.SupprimeCellule(i,j);
}

void Jeu::avance(){
    int m=Now.getRow();
    int n=Now.getCol();
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            int nbv= Now.NbVoisins(i,j);
            bool status= Now.EstOccupee(i,j);
            if (!status && nbv==3){ //reproduction
                Then.AjouteCellule(i,j);
            }
            else if (status &&(nbv==2||nbv==3)){
                Then.AjouteCellule(i,j);
            }
            else { //iso
                Then.SupprimeCellule(i,j);
            }
            // else if (status && nbv<=4){
            //     then.SupprimeCellule(i,j);
            // }
        }
    }
    Now=Then;//update 

}


int main(){

    // //test grille
    // Grille p(3,5);
    // p.affiche();
    // std::cout<<"\n";
    // p.AjouteCellule(1,4);
    // std::cout<<"\n";
    // std::cout<< p.EstOccupee(1,4) <<"\n";
    // std::cout<< p.EstOccupee(2,4);
    // std::cout<<"\n";
    // std::cout << p.NbVoisins(1,3)<<"\n";
    // p.affiche();
    // std::cout<<"\n";
    // p.SupprimeCellule(1,4);
    // p.affiche();

    Jeu g1(20,20);
    g1.AjouteCellule(5, 5);
    g1.AjouteCellule(5, 6);
    g1.AjouteCellule(5, 7);
    g1.afficheC();
    std::cout<<"\n";
    g1.avance();
    g1.afficheC();
    std::cout<<"\n";
    g1.avance();
    g1.afficheC();
    std::cout<<"\n";
    g1.avance();
    g1.afficheC();
    std::cout<<"\n";
    g1.avance();
    g1.afficheC();
    
}
