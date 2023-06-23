#include <iostream>
#include <string>


using namespace std;

class Rectangle{

    private:
        double longueur;
        double largeur;

    public:

        double getLongueur() const {return longueur;}
        double getLargeur() const {return largeur;}

        void setLongueur(double longueur){this->longueur = longueur;}
        void setLargeur(double largeur){this->largeur = largeur;}

        double surface() const {return longueur*largeur;}


};



int main()
{


    Rectangle rec;
    rec.setLongueur(6.8);
    rec.setLargeur(5.89);

    double longueur = rec.getLongueur();
    double largeur = rec.getLargeur();

    cout << "longeur: " << longueur << " largeur: " << largeur << endl;

    double surface = rec.surface();

    cout << "surface: " << surface << endl;














    return 0;
}