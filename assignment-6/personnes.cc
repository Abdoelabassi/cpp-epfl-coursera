#include <iostream>

using namespace std;

struct Personne
{
    double taille;
    int age;
    char sex;

};

void affiche_personne(Personne const &p)
{
    cout << "La taille de ce personne: " << p.taille << " cm "  << " \n son sex est " << p.sex << "\n son age: " << p.age << endl;

}

Personne naissance()
{
    Personne p;
    

        cout << "Entrez-vous age: ";
        cin >> p.age;
   
        cout << "Entrez-vous taille: ";
        cin >> p.taille;
    
        cout << "[M] or [F] or [NB](type B)?: ";
        cin >> p.sex;
    

    return p;

}

void anniversaire(Personne &p)
{
    ++(p.age);

    
}

int main()
{

    Personne Miles(naissance());
    affiche_personne(Miles);
    anniversaire(Miles);
    affiche_personne(Miles);












    return 0;
}