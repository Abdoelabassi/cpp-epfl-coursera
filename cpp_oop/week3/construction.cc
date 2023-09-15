#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Pour simplifier
typedef string Forme   ;
typedef string Couleur ;


class Brique
{
private:
  Forme   forme   ;
  Couleur couleur ;

public:
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/
 Brique(Forme _forme, Couleur _couleur) : forme(_forme), couleur(_couleur)
 {}
 Brique() = delete;

 friend ostream& afficher(ostream& sortie);
 ostream& afficher(ostream& sortie) const;

};

ostream& Brique::afficher(ostream& sortie) const
{
  if (couleur != "")
  {
    sortie << "(" << forme << ", " << couleur << ")" << endl;
  }
  else if (couleur == "")
  {
    sortie << forme << endl;
  }

}

ostream& operator<<(ostream& sortie, Brique const& brique)
{
  brique.afficher(sortie);
}

typedef vector<vector<vector<Brique>>> Base;

class Construction
{
  friend class Grader;



  private:
    Base contenu;

};

const Construction operator*(unsigned int n, Construction const& a)
{
}

const Construction operator/(unsigned int n, Construction const& a)
{
}

const Construction operator%(unsigned int n, Construction const& a)
{
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  // Modèles de briques
  Brique toitD("obliqueD", "rouge");
  Brique toitG("obliqueG", "rouge");
  Brique toitM(" pleine ", "rouge");
  Brique mur  (" pleine ", "blanc");
  Brique vide ("                 ", "");

  unsigned int largeur(4);
  unsigned int profondeur(3);
  unsigned int hauteur(3); // sans le toit

  // on construit les murs
  Construction maison( hauteur / ( profondeur % (largeur * mur) ) );

  // on construit le toit
  Construction toit(profondeur % ( toitG + 2*toitM + toitD ));
  toit ^= profondeur % (vide + toitG + toitD);

  // on pose le toit sur les murs
  maison ^= toit;

  // on admire notre construction
  cout << maison << endl;

  return 0;
}
