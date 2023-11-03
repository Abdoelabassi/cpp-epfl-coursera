#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

#define PI 3.14

using namespace std;

class Forme
{
    public:
    virtual double air() const = 0;
    virtual ~Forme(){}
    virtual void description() const{
        cout << "Ceci une forme!" << endl;
    }

};

class Cercle: public Forme
{
    public:
    Cercle(){}
    Cercle(unsigned int rayon_) : rayon(rayon_) {}
    void description() const{
        cout << "Ceci une circle!" << endl;
    }
    double air() const{
        double Air = PI*rayon*rayon;
        return Air;
    }

    private:
        unsigned int rayon;

};

class Triangle : public Forme
{
    private:
        double hauteur;
        double base;
    public:
        Triangle(double hauteur_, double base_): hauteur(hauteur_), base(base_) {}
    double air() const
    {
        return (base * hauteur) / 2;
    }
    void description() const
    {
        cout << "Ceci un traiangle!" << endl;
    }



};

void affichaeDesc(Forme &f)
{
    f.description();
    cout << "L'aire " << f.air() << endl;
}


int main() {
 Cercle c(5);
 Triangle t(10, 2);
 affichaeDesc(t);
 affichaeDesc(c);
 return 0;
}