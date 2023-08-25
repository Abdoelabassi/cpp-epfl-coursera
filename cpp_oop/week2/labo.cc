#include <iostream>
#include <string>
using namespace std;

class Souris
{
  /*****************************************************
    Complèter le code à  partir d'ici
  *******************************************************/ 
public:

    Souris(double poids, string couleur, unsigned int age = 0, unsigned int esperance_vie = 36)
        : poids(poids), couleur(couleur), age(age), esperance_vie(esperance_vie)
        {
            cout << "Une nouvelle souris !" << endl;
            clonee = false;
        }
    Souris(Souris const& souris)
     : poids(souris.poids), couleur(souris.couleur), age(souris.age), esperance_vie(4*souris.esperance_vie/5)
     {
        cout << "Clonage d'une souris ! " << endl;
        clonee = true;
     }


     ~Souris()
     {
        cout << "Fin d'une souris..." << endl;
     }

     void afficher(){
        if(clonee){
            cout << "Une souris " << couleur << ", clonee, " << "de  " << age << " mois et pesant " << poids << " grammes" << endl;
        }else{
            cout << "Une souris " << couleur << " de " << age << " mois et pesant " << poids << " grammes" << endl;
        }
     }

     void vieillir(){
        if(clonee && age > esperance_vie /2){
            age += 1;
            couleur = "verte";
        }
       
     }

     void evolue(){

        while(age < esperance_vie){
            age +=1;
            vieillir();
        }

     }

private:
    double poids;
    string couleur;
    unsigned int age;
    unsigned int esperance_vie;
    bool clonee;
  /*******************************************
   * Ne rien modifier aprés cette ligne.
   *******************************************/

}; // fin de la classe Souris

int main()
{
  Souris s1(50.0, "blanche", 2);
  Souris s2(45.0, "grise");
  Souris s3(s2);
  // ... un tableau peut-être...
  s1.afficher();
  s2.afficher();
  s3.afficher();
  s1.evolue();
  s2.evolue();
  s3.evolue();
  s1.afficher();
  s2.afficher();
  s3.afficher();
  return 0;
}