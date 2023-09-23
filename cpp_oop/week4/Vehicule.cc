#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Vehicule
{
    private:
        string marque;
        unsigned int date;
        double prix;

    public:
        Vehicule(string marque_, unsigned int date_, double prix_)
            : marque(marque_), date(date_), prix(prix_) {}

        void affiche(ostream& sortie) const {
            sortie << "La marque " << marque << ", date d'achat " << date << ", prix " << prix;
        }


};

class Voiture : public Vehicule
{
    private:
        double cylindree;
        double nombre_de_portes;
        double puissance;
        double kilometrage;

    public:
        Voiture(string marque_, unsigned int date_, double prix_, double cylindree_, double np_, double puissance_, double kilm_)
            : Vehicule(marque_, date_, prix_), cylindree(cylindree_), nombre_de_portes(np_), puissance(puissance_), kilometrage(kilm_)
            {}
        void affiche(ostream& sortie)
        {
            Vehicule::affiche(sortie);
            sortie << endl;
            sortie << cylindree << " Litres " << nombre_de_portes << " portes " << puissance << " CV " << kilometrage << " Km. ";
        }

};

class Avion : public Vehicule
{
    private:
        string type;
        unsigned int nombre_heure_vol;

    public:
        Avion(string marque_, unsigned int date_, double prix_, string type_, unsigned int nhvol_)
            : Vehicule(marque_, date_, prix_), type(type_), nombre_heure_vol(nhvol_)
            {}

        void affiche(ostream& sortie)
        {
            Vehicule::affiche(sortie);
            sortie << endl;
            sortie << nombre_heure_vol << " heures de vol ";
        }

};