#include <iostream>
#include <string>
#include <vector>
#include <cmath>




using namespace std;

class Point3D{

    public:
        void init(double x, double y, double z);
        void affiche();
        bool compare(Point3D p);



    private:
        double x;
        double y;
        double z;

};


int main(){

    Point3D point1;
    Point3D point2;
    Point3D point3;

    point1.init(1.4,1.5,2.5);
    point2.init(2.6,-5.6,-0.1);
    point3 = point1;

    cout << "Point 1: " ;
    point1.affiche();
    cout << "Point 2: ";
    point2.affiche();

    cout << "Point 1 est ";
    if(point1.compare(point3)){
        cout << "identique au ";
    }else{
        cout << "different au ";
    }

    cout << "Point 3 " << endl;

  





    return 0;
}

void Point3D::init(double xcor, double ycor, double zcor){

    x = xcor;
    y = ycor;
    z = zcor;


}

void Point3D::affiche(){

    cout << "Les coordonnees de ce point est " << "(" << x << ", " << y << ", " << z << ")" << endl;
}

bool Point3D::compare(Point3D p){
    return ((this->x == p.x ) and ( this->y == p.y ) and ( this->z == z ) ) ? true : false;
}