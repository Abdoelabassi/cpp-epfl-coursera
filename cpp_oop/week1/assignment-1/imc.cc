#include <iostream>
using namespace std;

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/
class Patient{
    public:
            void init(double mass, double height){
              if (mass > 0 and height > 0){
                this->masse = mass;
                this->hauteur = height;

              }else{
                this->masse = 0;
                this->hauteur = 0;
              }

            }

            void afficher(){
              cout << "Patient : " << masse << " kg " << "pour " << hauteur << " m" << endl;
            }

            double poids() const{
              return masse;

            }

            double taille() const {
              return hauteur;
            }

            double imc(){
              if (hauteur != 0){
                return masse/(hauteur*hauteur);
              }else{
                return 0;
              }
            }



    private:
            double masse;
            double hauteur;

};
/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  Patient quidam;
  double poids, taille;
  do {
    cout << "Entrez un poids (kg) et une taille (m) : ";
    cin >> poids >> taille;
    quidam.init(poids, taille);
    quidam.afficher();
    cout << "IMC : " << quidam.imc() << endl;
  } while (poids * taille != 0.0);
  return 0;
}
