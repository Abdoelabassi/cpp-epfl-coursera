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
 Brique(Forme f = "", Couleur c = "") : forme(f), couleur(c)
 {}
 Brique() = delete;


 ostream& afficher(ostream& sortie) const
{
   if (couleur == "") sortie << forme;
   else sortie << "( " << forme << ", " << couleur << " )";
  return sortie;

}

};

ostream& operator<<(ostream& sortie, Brique const& brique)
{
  return brique.afficher(sortie);
}

typedef vector<vector<vector<Brique>>> Base;

class Construction
{
  friend class Grader;
  private:
    Base contenu;
  
  public:
    
    Construction(Brique b)
    {
      contenu = {{{b}}};
    }
    

    ostream& afficher(ostream& sortie) const
    {
      for (int i = contenu.size() - 1; i >= 0; i--)
      {
        sortie << "Couche " << i << " : " << endl;
  
        for (unsigned int j(0); j < contenu[i].size(); j++)
        {
          for (unsigned int k(0); k < contenu[i][j].size(); k++)
          {
            sortie << contenu[i][j][k] << " ";
          }
          sortie << endl;
        }
      }

      return sortie;
      }
    
    void operator=(Construction const& b)
    {
        contenu.clear();
        move(b.contenu.begin(), b.contenu.end(), back_inserter(contenu));
    }


      void operator^=(Construction const& c)
      {
        move(c.contenu.begin(), c.contenu.end(), back_inserter(contenu));
      }

      void operator-=(Construction const& c)
      {
        if (c.contenu.size() >= contenu.size())
        {
          for (unsigned int i(0); i < contenu.size(); i++)
          {
            move(c.contenu[i].begin(), c.contenu[i].end(), back_inserter(contenu[i]));
          }
        }

      }

      void operator+=(Construction const& c)
      {
        if (c.contenu.size() >= contenu.size())
        {
          for (unsigned int i(0); i < contenu.size(); i++)
          {
            if (c.contenu[i].size() >= contenu[i].size())
            {
              for (unsigned int j(0); j < contenu[i].size(); j++)
              {
                move(c.contenu[i][j].begin(), c.contenu[i][j].end(), back_inserter(contenu[i][j]));

              }
            }
          }
        }
      }
    

};

ostream& operator<<(ostream& sortie, Construction const& c)
{
  return c.afficher(sortie);
}

const Construction operator^(Construction a, Construction const& b)
{
  a ^= b;
  return a;
}

const Construction operator-(Construction a, Construction const& b)
{
  a -= b;
  return a;

}

const Construction operator+(Construction a, Construction const& b)
{
  a += b;
  return a;
}

const Construction operator*(unsigned int n, Construction const& a)
{
  Construction c = a;
  for (unsigned int i(0); i < n - 1; i++)
  {
    c += a;
  }

  return c;
}

const Construction operator/(unsigned int n, Construction const& a)
{
  Construction c = a;
  for (unsigned int i(0); i < n - 1; i++)
  {
     c ^= a;
  }

  return c;
}

const Construction operator%(unsigned int n, Construction const& a)
{
  Construction c = a;
  for (unsigned int i(0); i < n - 1; i++)
  {
     c -= a;
  }

  return c;
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
