#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

class Vehicule
{
    public:
        Vehicule(string model_, unsigned int date_achat_,double prix_acaht_, double prix_courant_)
            : model(model_), date_achat(date_achat_), prix_achat(prix_acaht_), prix_courant(prix_courant_)
                {}
        virtual ~Vehicule();

        virtual void afficher(ostream&) const;
        

    protected:
        string model;
        unsigned int date_achat;
        double prix_achat;
        double prix_courant;
        


};

class Voiture : public Vehicule
{
    private:
        string marque;
        double prix;
        double cylindre;
        double kilometrage;
    public:
        Voiture(string name_, double prix_, double cylindre_, double kilometrage);

        

};

enum Avion_Type {HELICES, REACTION};

class Avion : public Vehicule
{
    private:
        Avion_Type motor;
        unsigned int hour_vol;
    public:
        Avion(Avion_Type motor_, unsigned int hour_vol_);

};

class Aeroport
{
    private:
        vector<Vehicule*> vehicules;
    public:
    void afficher(ostream&) const;
    void ajouter_vehicule(Vehicule*);
    void vider_aeroport();


};

void Aeroport::afficher(ostream& affiche) const
{
    for (auto const& ve : vehicules)
    {
        ve->afficher(affiche);
    }
}
void Aeroport::ajouter_vehicule(Vehicule* v)
{
    vehicules.push_back(v);
}

void Aeroport::vider_aeroport()
{
    vehicules.clear();
}