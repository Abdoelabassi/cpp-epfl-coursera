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
    Timbre(string nom_ = "plane", unsigned int annee_ = ANNEE_COURANTE, string pays_ = "Suisse", double valeur_faciale_ = 1.0)
      : nom(nom_), annee(annee_), pays(pays_), valeur_faciale(valeur_faciale_)
      {}

    void afficher(ostream& affichage) const
    {
        affichage << " de nom " << nom << " datant de " << annee << " (provenance " << pays << ") ayant pour valeur faciale " << valeur_faciale << " francs ";


    }

    double vente() const
    {
      double prix_vente(0);
      if (ANNEE_COURANTE - annee < 5)
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
    
    unsigned int age() const
    {
      unsigned int age_ = ANNEE_COURANTE - annee;
      return age_; 
    }
    
};

ostream& operator<<(ostream& affichage, const Timbre& t)
    {
      affichage << "Timbre";
      t.afficher(affichage);
      return affichage;
    }

class Rare : public Timbre
{
  public:
    Rare(string nom_ = "plane", unsigned int annee_ = 2014, string pays_ = "Suisse", double valeur_faciale_ = 1.0, unsigned int exemplaire_ = 100)
      : Timbre(nom_, annee_, pays_, valeur_faciale_), exemplaire(exemplaire_)
      {}

    unsigned int nb_exemplaires() const
    {
      return exemplaire;
    }
    void afficher(ostream& affichage) const
    {
      Timbre::afficher(affichage);
    }

   
  
  double vente()
  {
    double prix_vente(0);

    if (exemplaire < 100)
    {
      prix_vente += PRIX_BASE_TRES_RARE * (age() / 10.0);
      return prix_vente;
    }
    else if (exemplaire > 100 && exemplaire < 1000)
    {
      prix_vente += PRIX_BASE_RARE * (age() / 10.0);
      return prix_vente;
    }
    else
    {
      prix_vente += PRIX_BASE_PEU_RARE * (age() / 10.0);
      return prix_vente;
    }
  }

  private:
    unsigned int exemplaire;

};

ostream& operator<<(ostream& affichage, Rare const& r)
{
  affichage << "Timbre rare (" << r.nb_exemplaires() << " ex.)";
  r.afficher(affichage);
  return affichage;
}

class Commemoratif : public Timbre
{
  public:
    Commemoratif(string nom_ = "plane", unsigned int annee_ = 2014, string pays_ = "Suisse", double valeur_faciale_ = 1.0)
      : Timbre(nom_, annee_, pays_, valeur_faciale_)
      {}

   
    double vente() const
    {
      return (Timbre::vente() * 2);
    }

    void afficher(ostream& affichage) const
    {
      Timbre::afficher(affichage);
    }
};

ostream& operator<<(ostream& affichage, Commemoratif const& c)
{
      affichage << "Timbre commémoratif";
      c.afficher(affichage);
      return affichage;
}

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
