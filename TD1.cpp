#include<iostream>

class Point {
    private:
    double x;
    double y; 

    public
    double getX(){
        return this->x; 
    }
    double getY(){
        return this->y;
    }
    void afficher (){
        double a = this->x;
        double b = this->y;
        std::cout << a,b ;
    }

    
}

class Droit {
    private:
    Point p1,p2;


    public:

    Point getP1(){
        return This->p1;
    }
    Point getP2(){
        return This->p2;
    }

    bool Testappart (Point p3 ){
        Point a = This->p1;
        Point b = This->p2;
        double xa = a.getX();
        double xb =b.getX();
        double ya = a.getY();
        double yb = b.getY();
        double xp = p3.getX();
        double yp = p3.getY();

        double xab = xb - xa;
        double yab = yb - yb
        double xap = xp -xa;
        double yap = yp -ya
        return (((xab*yap)-(yab-yap))==0);


    }
    double getVecX(){
        Point a = This->p1;
        Point b = This->p2;
        return a.getX()-b.getX()};
    double getVecY() {
        Point a = This->p1;
        Point b = This->p2;
        return a.getY()- b.getVecY()}

    bool TestPara (Droit d){
        double xab = getVecX();
        double yab = getVecY();
        double xd = d.getVecX();
        double yd = d.getVecY();
         return 

    }
    
}