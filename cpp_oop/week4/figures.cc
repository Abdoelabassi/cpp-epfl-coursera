#include <iostream>
#include <vector>
#include <cmath>

#define PI = 3.14;

using namespace std;

class Figure
{
    protected:
        double x, y;

    public:
        Figure(double x_ = 0.0, double y_ = 0.0)
            : x(x_), y(y_) {}

        ostream& affiche(ostream& sortie)
        {
            sortie << "Le centre = " << "( " << x << ", " << y << " )";
            return sortie;
        }

        void getPoint(double& abscisse, double& ordonee) const
        {
            abscisse = x;
            ordonee = y;
        }

        void setPoint(double abscisse, double ordonnee)
        {
            x = abscisse;
            y = ordonnee;
        }

};


class Rectangle : public Figure
{
    private:
        double longeur;
        double largeur;

    public:

        Rectangle(double lo_, double la_, double x_, double y_)
            : Figure(x_, y_), longeur(lo_), largeur(la_)
        {}

        void affiche(ostream&);
        double Surface() const {return longeur*largeur;}
        // getters
        double getLongeur() const {return longeur;}
        double getLargeur() const {return largeur;}
        //setters
        void setLongeur(double longeur_) {this->longeur = longeur_;}
        void setLargeur(double largeur_) {this->largeur = largeur_;}

};

class Circle : public Figure
{
    private:
        double Rayon;

    public:


        Circle(double r_, double x_ = 0.0, double y_ = 0.0 )
            : Figure(x_, y_), Rayon(r_)
            {}

        void affiche(ostream&);

        double Surface() const {return 2*M_PI*pow(Rayon, 2);}
        
        // getters
        double getRayon() const{return Rayon;}
        // setters
        void setRayon(double rayon_)
        {
            if (rayon_ < 0.0 ) rayon_ = 0.0;
            this->Rayon = rayon_;
        }
        void setCentre(double x_, double y_)
        {
            x = x_;
            y = y_;
        }

};

class RectangleColoree : public Rectangle
{
    private:
        unsigned int couleur;

    public:
        RectangleColoree(double lo_, double la_, unsigned int c_)
            : Rectangle(lo_, la_, 0.0, 0.0), couleur(c_)
            {}


};

void Circle::affiche(ostream& sortie)
{
    Figure::affiche(sortie);
    sortie << ", rayon = " << Rayon;
    
}

void Rectangle::affiche(ostream& sortie)
{
    Figure::affiche(sortie);
    sortie << ", longeur = " << longeur << ", largeur = " << largeur;
}

int main()
{

    RectangleColoree rc(4.5, 2.45, 4);
    cout << "Largeur: " << rc.getLargeur() << endl;
    cout << "Longeur: " << rc.getLongeur() << endl;

    rc.affiche(cout);
    cout << endl;

    Circle c(4.5, 1.3, 1.7);
    c.setCentre(0.3, 0.4);
    c.setRayon(4.5);
    c.affiche(cout);
    cout << endl;

    Rectangle r(5.5, 5.6, 0.0, 1.5);
    r.setLargeur(4.5);
    r.affiche(cout);









    return (0);
}