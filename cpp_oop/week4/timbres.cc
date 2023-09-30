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
    enum PRIX_BASE {PRIX_BASE_TRES_RARE = 600, PRIX_BASE_RARE = 400, PRIX_BASE_PEU_RARE = 50};

  public:
    Timbre(string nom_, unsigned int annee_, string pays_ = "Suisse", double valeur_faciale_ = 1.0)
      : nom(nom_), annee(annee_), pays(pays_), valeur_faciale(valeur_faciale_)
      {}
    friend ostream& operator<<(ostream& affichage, const Timbre& t);


    double vente()
    {
      double prix_vente(0);
      if (ANNEE_COURANTE - annee <= 5)
      {
        prix_vente += valeur_faciale;
        return prix_vente;
      }
      else
      {
        prix_vente += valeur_faciale*2.5*(ANNEE_COURANTE - annee);
        return prix_vente;

      }
    }
    
    unsigned int age()
    {
      unsigned int age_ = ANNEE_COURANTE - annee;
      return age_; 
    }
    



};

ostream& operator<<(ostream& affichage, const Timbre& t)
    {
      affichage << "Timbre de nom " << t.nom << " datant de " << t.annee << "(provenance " << t.pays << ") ayant pour valeur faciale " << t.valeur_faciale << " francs ";
      return affichage;
    }

class Rare : public Timbre
{
  public:
    Rare(string nom_, unsigned int annee_, string pays_, double valeur_faciale_, unsigned int exemplaires_)
      : Timbre(nom_, annee_, pays_, valeur_faciale_), exemplaires(exemplaires_)
      {}


  private:
    unsigned int exemplaires;

};

class Commemoratif : public Timbre
{
  public:
    Commemoratif(string nom_, unsigned int annee_, string pays_, double valeur_faciale_)
      : Timbre(nom_, annee_, pays_, valeur_faciale_)
      {}
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
