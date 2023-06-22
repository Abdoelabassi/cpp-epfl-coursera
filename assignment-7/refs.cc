#include <iostream>
#include <string>


using namespace std;


struct Maison {

    string addresse;

};

struct Personne {

    string nom;
    Maison* masion;

};

void affiche(const Personne& p){

    cout << p.nom << " habite " << (*(p.masion)).addresse << endl;

    


}



int main()
{

    Maison m1 = {"104 bulvard Fes"};
    Maison m2 = {"192 avenue Ouad EL Makahzine"};

    Personne jefferson = {"Jefferson", &m1};
    Personne katie = {"Katie", &m2};

    affiche(jefferson); affiche(katie);









    return 0;
}