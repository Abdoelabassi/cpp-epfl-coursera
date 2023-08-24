#include <iostream>
#include <string>
using namespace std;

class Souris
{
  /*****************************************************
    ComplÃ©ter le code Ã  partir d'ici
  *******************************************************/
public:

    Souris(double poids, string colour, unsigned int age = 0, unsigned int esperance_vie = 36)
        : poids(poids), colour(colour), age(age), esperance_vie(esperance_vie)
        {
            cout << "Une nouvelle souris !;" << endl;
        }
    Souris(Souris const& souris)
     : poids(souris.poids), colour(souris.colour), age(souris.age), esperance_vie(4*souris.esperance_vie/5)
     {
        cout << "Clonage d'une souris !; " << endl;
     }


     ~Souris()
     {
        cout << "Fin d'une souris...;" << endl;
     }

     void afficher(){
        if(clonee){
            cout << "Une souris " << colour << ", clonee, " << " de  " << age << " mois et pesant " << poids << " grammes" << endl;
        }else{
            cout << "Une souris " << colour << " de " << age << " mois et pesant " << poids << " grammes" << endl;
        }
     }

     void vieillir(){
        if(clonee){
            age += 1;
        }
        if(age > esperance_vie / 2 ){
            colour = "verte";
        }
     }

     void evolue(){

        while(age < esperance_vie){
            vieillir();
        }

     }

private:
    double poids;
    string colour;
    unsigned int age;
    unsigned int esperance_vie;
    bool clonee;
  /*******************************************
   * Ne rien modifier aprÃ¨s cette ligne.
   *******************************************/

}; // fin de la classe Souris

int main()
{
  Souris s1(50.0, "blanche", 2);
  Souris s2(45.0, "grise");
  Souris s3(s2);
  // ... un tableau peut-Ãªtre...
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