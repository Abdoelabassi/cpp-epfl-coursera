#include <iostream>
#include <string>
using namespace std;

class Timbre
{
private:
  static constexpr unsigned int ANNEE_COURANTE = 2016;

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/
  protected:
    string nom;
    unsigned int annee;
    string pays;
    double valeur_faciale;

  public:
    Timbre(string nom_, unsigned int annee_, string pays_ = "Suisse", double valeur_faciale_ = 1.0)
      : nom(nom_), annee(annee_). pays(pays_), valeur_faciale(valeur_faciale_)
      {}

    double vente()
    {
      double prix_vente = 50 * (annee / 10.0);
      return prix_vente;
    }
    
    unsigned int age()
    {
      unsigned int age_ = ANNEE_COURANTE - annee;
      return age_; 
    }
    void affiche(ostream& affichage)
    {
      affichage << "Timbre de nom " << nom << " datant de " << annee << "(provenance " << pays << ") ayant pour valeur faciale " << valeur_faciale << " francs ";
    }



};

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/
int main()
{
  /* Ordre des arguments :
  *  nom, année d'émission, pays, valeur faciale, nombre d'exemplaires
  */
  Rare t1( "Guarana-4574", 1960, "Mexique", 0.2, 98 );
  Rare t2( "Yoddle-201"  , 1916, "Suisse" , 0.8,  3 );

  /* Ordre des arguments :
  *  nom, année d'émission, pays, valeur faciale, nombre d'exemplaires
  */
  Commemoratif t3( "700eme-501"  , 2002, "Suisse", 1.5 );
  Timbre       t4( "Setchuan-302", 2004, "Chine" , 0.2 );

  /* Nous n'avons pas encore le polymorphisme :-(
   * (=> pas moyen de faire sans copie ici :-( )  */
  cout << t1 << endl;
  cout << "Prix vente : " << t1.vente() << " francs" << endl;
  cout << t2 << endl;
  cout << "Prix vente : " << t2.vente() << " francs" << endl;
  cout << t3 << endl;
  cout << "Prix vente : " << t3.vente() << " francs" << endl;
  cout << t4 << endl;
  cout << "Prix vente : " << t4.vente() << " francs" << endl;

  return 0;
}
