#include <iostream>
#include <array>
#include <cmath>

using namespace std;


class Point3D {

    public:
        void init(double x, double y, double z){
            this->x=x; this->y=y; this->z=z;
        }

        double getx() const { return x;}
        double gety() const {return y;}
        double getz() const {return z;}

        void init(){
            cout << "Construction d'un nouveau point " << endl;
            cout << "Veuillez entrer x: ";
            cin >> x;
            cout << "Veuillez entrer y: ";
            cin >> y;
            cout << "Veuillez entrer z: ";
            cin >> z;
        }

       
    private:
        double x,y,z;

};

 double distance(Point3D const &p1, Point3D const &p2){

            return sqrt(
                    (p1.getx() - p2.getx() )*(p1.getx() - p2.getx() )
                +   (p1.gety() - p2.gety() )*(p1.gety() - p2.gety() )
                +   (p1.getz() - p2.getz() )*(p1.getz() - p2.getz() )
            );

        }



class Triangle {

    public:
    void init(){
        array<Point3D,3> sommees;
        for (auto &p: sommees){
            p.init();
        }
        cotes[0] = distance(sommees[0], sommees[1]);
        cotes[1] = distance(sommees[1], sommees[2]);
        cotes[2] = distance(sommees[2], sommees[0]);
    }

    bool is_isoceles(){
        return (cotes[0] == cotes[1]) or (cotes[1] == cotes[2]) or (cotes[2] == cotes[0]) ;
    }

    double perimeter() const {
        return cotes[0] + cotes[1] + cotes[2];
    }

       

    private:
        array<double,3> cotes;

};

int main(){

    Triangle t;
    t.init();

    cout << "Perimeter " << t.perimeter() << endl;
    cout << "Ce triangle ";
    if (t.is_isoceles()){
        cout << "est ";
    }else{
        cout << "n'est pas ";
    }

    cout << "isocele ! " << endl;




    return 0;
}


