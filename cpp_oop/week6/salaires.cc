#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
/**
 * Cet exercice vous permettra de concevoir une hiérarchie de classes comportant de l'héritage multiple. Il vous servira
    également de révision pour la notion de collections hétérogène vue la semaine passée.
    Le directeur d'une entreprise de produits chimiques souhaite gérer les salaires et primes de ses employés au moyen d'un
    programme C++.
    Un employé est caractérisé par son nom, son prénom, son âge et sa date d'entrée en service dans l'entreprise.
    Dans un fichier salaires.cc, codez une classe abstraite Employe dotée des attributs nécessaires, d'une méthode
    virtuelle pure calculer_salaire (ce calcul dépendra en effet du type de l'employé) et d'une méthode virtuelle
    get_nom retournant la chaîne de caractères "L'employé " suivit du prénom et du nom.
    Dotez également votre classe d'un constructeur prenant en paramètre l'ensemble des attributs nécessaires et d'un destructeur
    virtuel vide
*/

using namespace std;

class Employee
{
    protected:
        const string nom;
        const string prenom;
        unsigned int age;
        unsigned int date_entree;
    public:
        Employee(const string nom_ = "Halbert", const string prenom_ = "Jim", unsigned int age_ = 32, unsigned int date_entree_ = 1996)
        : nom(nom_), prenom(prenom_), age(age_), date_entree(date_entree_)
        {
            cout << "Nouveau Emplye " << endl;
        }
        virtual ~Employee(){}
        
        virtual void calculer_salaire() const = 0;
        virtual const string get_nom() const
        {
            const string mon_nom = "L'emplye " + prenom + " " + nom;

            return mon_nom;
        }

};

class Vente: public Employee
{


};