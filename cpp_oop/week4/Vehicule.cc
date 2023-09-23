#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Vehicule
{
    private:
        unsigned int date;

    protected:
        string marque;
        double prix;

    public:
        Vehicule(string marque_, unsigned int date_, double prix_)
            : marque(marque_), date(date_), prix(prix_) {}

        void affiche(ostream& sortie) const {
            sortie << "La marque: " << marque << ", date d'achat: " << date << ", prix d'achat: " << prix;
        }

    void calculPrix()
    {
        prix /= 0.001;
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
            sortie << "---------Voiture----------" << endl;
            Vehicule::affiche(sortie);
            sortie << endl;
            sortie << cylindree << " Litres " << nombre_de_portes << " portes " << puissance << " CV " << kilometrage << " Km. " << endl;
        }

        void calculPrix()
        {
            if (prix < 0.0)
            {
                prix = 0.0;
            }
            else if (kilometrage >= 10000)
            {
                prix /= 0.05;

            }
            else if (marque == "Fiat" || marque == "Renault")
            {
                prix /= 0.1;
            }
            else if (marque == "Ferrari" || marque == "Porsche")
            {
                prix /= 0.2;

            }
            else
            {
                prix /= 0.02;
            }

            cout << "prix actuel: " << prix;
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
            sortie << "-------Avion a " << type << "-----------" << endl;
            Vehicule::affiche(sortie);
            sortie << endl;
            sortie << nombre_heure_vol << " heures de vol " << endl;
        }

        void calculPrix()
        {
            if (prix < 0.0)
            {
                prix = 0.0;
            }
            else if (nombre_heure_vol == 1000)
            {
                prix /= 0.1;
            }
            else if (nombre_heure_vol == 100)
            {
                prix /= 0.1;
            }

            cout << "prix actuel: " << prix;
           
        }

};

int main()
{

  vector<Voiture> garage;
  vector<Avion>   hangar;
 
  string REACTION = "REACTION";
  string HELICES = "HELICES";


  garage.push_back(Voiture("Peugeot", 1998, 147325.79, 2.5, 5, 180.0,
                           12000));
  garage.push_back(Voiture("Porsche", 1985, 250000.00, 6.5, 2, 280.0,
                           81320));
  garage.push_back(Voiture("Fiat",    2001,   7327.30, 1.6, 3,  65.0, 
                           3000));
  hangar.push_back(Avion("Cessna",      1972, 1230673.90, HELICES,  
                         250));
  hangar.push_back(Avion("Nain Connu", 1992, 4321098.00, REACTION,
                         1300));


  for (auto voiture : garage)
  {
    voiture.calculPrix();
    voiture.affiche(cout);
  }

  for (auto avion : hangar)
  {
    avion.calculPrix();
    avion.affiche(cout);
  }






    return 0;
}