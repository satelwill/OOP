#include<iostream>
#include<cmath>

class Complexe {
    private:
    double re;
    double im ;
    public:
    //constructer
    Complexe( double re, double im){
        this->re=re;
        this->im=im;
    };
    Complexe(const Complexe &c){
        this->re=c.re;
        this->im=c.im;
    };
    double getre(){
        return this->re;
    }
    double getim(){
        return this->im;
    }
    double modu(){
        double a=this->re;
        double b=this->im;
        return std::sqrt(a*a+b*b);
    }
    double ang(){
        double a=this->re;
        double b=this->im;
        return std::atan(b/a);

    }
    void afficher(){
        std:: cout << this->re << "+" <<this->im << "i" << std::endl;

    }
    Complexe operator+=(const Complexe &c){
        this->re+=c.re;
        this->im+=c.im;
        return *this;
        
    }
};

int main(){
    Complexe z1(2.0,5.0);
    Complexe z2(3.0,2.0);
    z1+=z2;
    z1.afficher();
    std::cout<<z1.modu()<<"\n";
    std::cout<<z1.ang()<<"\n";
}