#include <iostream>
#include <vector>
#include <string>

using namespace std;


/*
* Une société protectrice des animaux souhaite commercialiser des animaux en peluche à l'effigie de ses protégés pour
* renflouer ses caisses.
*/

class Animal
{
    protected:
        const char* nom;
        const char* continent;
    public:
        Animal(const char* nom_ = "Lion", const char* continent_ = "Africa"): nom(nom_), continent(continent_)
        {
            cout << "Nouvel animal protege " << endl;
        }
        ~Animal()
        {
            cout << "Je ne suis plus protege" << endl;
        }


    void affiche() const
    {
        cout << "Je suis un " << nom << ", et je vis en " << continent << endl;
    }


};

class EnDanger
{
    protected:
        unsigned int nombre;
    public:
        EnDanger(unsigned int n = 3): nombre(n)
        {
            cout << "Nouvel animal en danger " << endl;
        }
        ~EnDanger()
        {
            cout << "ouf!, Je ne suis plus en danger " << endl;
        }
    void affiche() const
    {
        cout << "Il ne rest que " << nombre << " de mon espece sur Terre !" << endl;
    }

};

class Gadget
{
    protected:
        const char* nom_produit;
        double prix;

    public:
        Gadget(const char* nom_ = "Ming", double prix_ = 20): nom_produit(nom_), prix(prix_)
        {
            cout << "Nouveau Gadget ! " << endl;
        }
        ~Gadget()
        {
            cout << "Je ne suis plus un gadget ! " << endl;
        }
    void affiche() const
    {
        cout << "Mon nom est " << nom_produit << endl;
    }

    void affiche_prix() const
    {
        cout << "Achetez-moi pour " << prix << " francs et vous contribeuez a ma sauvez " << endl;
    }

};

class Peluche: public Animal, public EnDanger, public Gadget
{
    public:
        Peluche(const char* nom_, const char* nom_produit_, const char* continent_, double prix_, unsigned int n_especes_)
        : Animal(nom_, continent_), EnDanger(n_especes_), Gadget(nom_produit_, prix_)
        {
            cout << "Un Nouvel Peluche !" << endl;
        }
        ~Peluche()
        {
            cout << "Je ne suis plus un Peluche! " << endl;
        }
    using Animal::affiche;
    using EnDanger::affiche;
    using Gadget::affiche;
    using Gadget::affiche_prix;

    void etiquette() const
    {
        cout << "Hello " << endl;
        Gadget::affiche();
        Animal::affiche();
        EnDanger::affiche();
        Gadget::affiche_prix();

    }


};

int main()
{ 
  Peluche panda("Panda","Ming","Asie", 200, 20.0);
  Peluche serpent("Cobra","Ssss","Asie", 500, 10.0);
  Peluche toucan("Toucan","Bello","Amérique", 1000, 15.0);
 
  panda.etiquette();
  serpent.etiquette();
  toucan.etiquette();
  return 0;
}
