#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


class Point3D
{
    protected:
        double x, y, z;
    
    public:
        Point3D() : x(0.0), y(0.0), z(0.0)
        {}
        Point3D(double x_, double y_, double z_)
            : x(x_), y(y_), z(z_)
        {}

        // getters
        double getX() const {return x;}
        double getY() const {return y;}
        double getZ() const {return z;}
        // comparaison
        bool operator==(Point3D const& autre)
        {
            if (x == autre.x && y == autre.y && z == autre.z)
            {
                return true;

            }
            return false;

        }

};

class Vecteur : public Point3D
{
    public:
        Vecteur() : Point3D() {}
        Vecteur(double x_, double y_, double z_)
        : Point3D(x_, y_, z_)
        {}
        friend double operator*(const Vecteur& v1, const Vecteur& v2);

        Vecteur& operator+=(const Vecteur& vect)
        {
            Vecteur v;
            x += vect.x;
            y += vect.y;
            z += vect.z;

            return *this;

        }

        Vecteur& operator-=(const Vecteur& vect)
        {
            Vecteur v;
            x -= vect.x;
            y -= vect.y;
            z -= vect.z;

            return *this;

        }
        // affiche
        void affiche(ostream& affichage)
        {
            affichage << "(" << x << ", " << y << ", " << z << ")";
        }
        // norm
        double norm() const
        {
            double n;
            n = sqrt(x*x + y*y + z*z);
            return n;
        }
        // angle entre deux vecteur
        double angle(const Vecteur& v1, const Vecteur& v2)
        {
            double phi;
            phi = acos(v1*v2/(v1.norm() * v2.norm()));
            return phi;
        }
    
       
        // operator opposee
        const Vecteur operator-() const {

            return Vecteur(-x, -y, -z);

        }

        Vecteur& operator*=(double a)
        {
            
            x *= a;
            y *= a;
            z *= a;

            return *this;
        }


};

        const Vecteur operator+(Vecteur v1, const Vecteur& v2)
        {
            return v1 += v2;

        }

        const Vecteur operator-(Vecteur v1, const Vecteur& v2)
        {
            return v1 -= v2;

        }

        const Vecteur operator*(Vecteur v, double a)
        {
            return v *= a;
        }

        const Vecteur operator*(double a, const Vecteur& v)
        {
            return v*a;
        }
        // produit scalaire
        double operator*(const Vecteur& v1, const Vecteur& v2)
        {
            double produit_vect;
            produit_vect = v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
            return produit_vect;

        }

       
class VecteurUnitaire : public Vecteur
{
    public:
        VecteurUnitaire() : Vecteur() {}
        VecteurUnitaire(double x_, double y_, double z_)
            : Vecteur(x_, y_, z_)
            {}
        // norm
        double norm() const
        {
            return 1.0;
        }
        // angle
        double angle(const VecteurUnitaire& u1, const VecteurUnitaire& u2) 
        {
            return (acos(u1*u2/(u1.norm() * u2.norm())));
        }



};

int main()
{
    Vecteur v1(1, 2, -0.1), v2(2.6, 3.5, 4.1);

    cout << "Somme de deux vecteur " << endl;
    cout << "v1 cordonnees: ";
    v1.affiche(cout);
    cout << endl;
    cout << "v2 cordonnees: ";
    v2.affiche(cout);
    cout << endl;
    Vecteur w(v1 + v2);
    cout << "w(v1 + v2) cordonnees: ";
    w.affiche(cout);
    cout << endl;
    w = v2 + v1;
    cout << "w(v2 + v1) cordonnees: ";
    w.affiche(cout);
    cout << endl;
    cout << "Substraction de deux vecteurs" << endl;
    Vecteur e(v1 - v2);
    cout << "e cordonnees: ";
    e.affiche(cout);
    cout << endl;
    cout << "Produit scalaire" << endl;
    double p(v1*v2);
    cout << "p = " << p << endl;
    cout << "multiplication par un scalaire" << endl;
    Vecteur S(2*v1);
    cout << "2xS cordonnees: ";
    S.affiche(cout);
    cout << endl;
    double angl(v1.angle(v1, v2));
    cout << "angle entre v1 et v2 en Deg: " << angl << endl;









    return 0;
}