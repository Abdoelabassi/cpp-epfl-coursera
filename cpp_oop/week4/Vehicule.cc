#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

enum Type_Avion {REACTION , HELICES};

class Vehicule
{

    protected:
        string marque;
        unsigned int date;
        double prix_achat;
        double prix_courant;


    public:
        Vehicule(string marque_, unsigned int date_, double prix_)
            : marque(marque_), date(date_), prix_achat(prix_), prix_courant(prix_) 
            {}

        void affiche(ostream& sortie) const {
            sortie << "La marque: " << marque << ", date d'achat: " << date 
            << ", prix d'achat: " << prix_achat << ", prix actuel: " << prix_courant;
        }

    void calculPrix()
    {
        double decote((2023 - date)*0.01);
        prix_courant = max(0.0, (1.0 - decote)*prix_achat);    
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

        void calculePrix()
        {
            double decote((2023 - date)*0.02);
            decote += 0.05 * (kilometrage/10000);

            if (marque == "Fiat" || marque == "Renault")
            {
                decote += 0.1;
            }
            else if (marque == "Ferrari" || marque == "Porsche")
            {
                decote -= 0.2;
            }

            prix_courant = max(0.0, (1.0 - decote)*prix_achat);

            

        }

};

class Avion : public Vehicule
{
    private:
        Type_Avion mouteur;
        unsigned int nombre_heure_vol;

    public:
        Avion(string marque_, unsigned int date_, double prix_, Type_Avion mouteur_, unsigned int nhvol_)
            : Vehicule(marque_, date_, prix_), mouteur(mouteur_), nombre_heure_vol(nhvol_)
            {}

        void affiche(ostream& sortie)
        {
            sortie << "-------Avion a ";
            if (mouteur == HELICES) sortie << "hélices";
            else sortie << "réaction";
            sortie << "---------" << endl;
            Vehicule::affiche(sortie);
            sortie << endl;
            sortie << nombre_heure_vol << " heures de vol " << endl;
        }

        void calculePrix()
        {
            double decote;

            if (mouteur == HELICES)
            {
                decote += 0.1*(nombre_heure_vol/1000);
            }
            else
            {
                decote += 0.1*(nombre_heure_vol/100);
            }

            prix_courant = max(0.0, (1.0 - decote)*prix_achat);
            
           
           
        }

};

int main()
{

  vector<Voiture> garage;
  vector<Avion>   hangar;
 


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

    cout << "--------------------------------------------------------------  ANNEE : 2023 ----------------------------------------- " << endl; 

  for (auto voiture : garage)
  {
    voiture.calculePrix();
    voiture.affiche(cout);
  }

  for (auto avion : hangar)
  {
    avion.calculePrix();
    avion.affiche(cout);
  }






    return 0;
}