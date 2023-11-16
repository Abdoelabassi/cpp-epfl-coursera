#include <iostream>
#include <cmath>
using namespace std;

enum Pavillon { JollyRogers, CompagnieDuSenegal, CompagnieDOstende };

enum Etat { Intact, Endommage, Coule };

int sq(int x)
{
  return x*x;
}

class Coordonnees
{
public:
  Coordonnees(int un_x, int un_y) : x_(un_x), y_(un_y) {}
  int x() const {
    return x_;
  }
  int y() const {
    return y_;
  }
  void operator+=(Coordonnees const& autre); // à définir plus bas
private:
  int x_;
  int y_;
};

class Navire
{
  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/
  protected:
    Coordonnees position_;
    Pavillon  pavillon_;
    Etat etat_;
    string nom_generique;
    const double rayon_rencontre = 10;

  public:
    Navire(int x_, int y_, Pavillon p, Etat etat = Intact, string nom = ""): position_(x_, y_),  pavillon_(p), etat_(etat), nom_generique(nom) {}

  Coordonnees const& position() const
  {
    return position_;
  }
  Etat etat() const
  {
    return etat_;
  }
  void avancer(int de_x, int de_y)
  {
    Coordonnees cord(de_x, de_y);
    if ( etat_ != Coule)
    {
      position_ += cord;
    }
  }
  void renflouer(){etat_ = Intact;}

  ostream& afficher(ostream& affichage) const;
  
  virtual void attaque(Navire& autre)  = 0;
  virtual void replique(Navire& autre) = 0;
  virtual void est_touche() = 0;
  void rencontrer(Navire& autre);

};

class Pirate: public virtual Navire
{
  public:
    Pirate(int x_, int y_, Pavillon p, Etat etat_ = Intact, string nom = "bateau pirate") : Navire(x_, y_, p, etat_, nom){}

  void attaque(Navire& autre)
  {
    if (this->etat() != Coule && autre.etat() != Coule)
    {
      			cout << "A l'abordage !" << endl;
            autre.est_touche();
    }
  }
  void replique(Navire& autre)
  {
    if (this->etat() != Coule)
    {
      	cout << "Non mais, ils nous attaquent ! On riposte !!" << endl;
        this->attaque(autre);

    }
  }

  void est_touche(){
    if (etat_ == Intact) etat_ = Endommage;
    else etat_ = Coule;
  }
};

class Marchand: public virtual Navire
{
  public:
    Marchand(int x_, int y_, Pavillon p, Etat etat = Intact, string nom = "navire marchand"): Navire(x_, y_, p, etat, nom) {}
  
  void attaque(Navire& autre)
	{
		if (this->etat() != Coule && autre.etat() != Coule) cout << "On vous aura ! (insultes) " << endl;
	}
	void replique(Navire& autre)
	{
		if (this->etat() == Coule) cout << "SOS je coule !" << endl;
		else cout << "Même pas peur !" << endl;
	}
	void est_touche()
	{
		etat_ = Coule;
	}

  

};
class Felon: public Marchand, public Pirate
{
  public:
    Felon(int x_, int y_, Pavillon pavillon, Etat etat= Intact, string nom = "navire félon")
    : Navire(x_, y_, pavillon, etat, nom) ,Marchand(x_, y_, pavillon, etat, nom), Pirate(x_, y_, pavillon, etat, nom){}

  void attaque(Navire& autre)
	{
		Pirate::attaque(autre);
	}
	void replique(Navire& autre)
	{
		Marchand::replique(autre);
	}
	void est_touche()
	{
		Pirate::est_touche();
	}


};

void Coordonnees::operator+=(Coordonnees const& autre)
{
  // à définir ici
  x_ += autre.x();
  y_ += autre.y();

}
double distance(Coordonnees const& cord1, Coordonnees const& cord2)
{
  double d = sqrt(sq(cord1.x() - cord2.x()) + sq(cord1.y() - cord2.y()));
  return d;
}

ostream& operator<<(ostream& affichage, Coordonnees const& autre)
{
  affichage << "(" << autre.x() << ", " << autre.y() << ")";
  return affichage;
}
ostream& operator<<(ostream& affichage, Pavillon const& pav)
{
  switch (pav)
  {
  case JollyRogers:
    affichage << "pirate";
    break;
  case CompagnieDuSenegal:
    affichage << "français";
    break;
  case CompagnieDOstende:
    affichage << "autrichien";
    break;
  
  default:
    affichage << "pavillon inconnu";
    break;
  }

  return affichage;
}
ostream& operator<<(ostream& affichage, Etat const& etat)
{
  switch (etat)
  {
  case Intact:
    affichage << "intact";
    break;
  case Endommage:
    affichage << "ayant subi des dommages";
    break;
  case Coule:
    affichage << "coulé";
    break;
  
  default:
    affichage << "état inconnu";
    break;
  }

  return affichage;
}

ostream& operator<<(ostream& affichage, Navire const& autre)
  {
    return autre.afficher(affichage);
  }

ostream& Navire::afficher(ostream& affichage) const
  {
     affichage << nom_generique << " en " << position_ << " battant pavillon " <<  pavillon_ << ", " << etat_;
     return affichage;
  }
double distance(Navire const& n1, Navire const& n2)
  {
    double d = sqrt(sq(n1.position().x() - n2.position().x()) + sq(n1.position().y() - n2.position().y()));
    return d;
  }
  void Navire::rencontrer(Navire& autre)
{
	if (distance(*this, autre) < rayon_rencontre && this->etat_ != Coule && autre.etat_ != Coule && this->pavillon_ != autre.pavillon_)
	{
		this->attaque(autre);
		autre.replique(*this);
	}
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void rencontre(Navire& ship1, Navire& ship2)
{
  cout << "Avant la rencontre :" << endl;
  cout << ship1 << endl;
  cout << ship2 << endl;
  cout << "Distance : " << distance(ship1, ship2) << endl;
  ship1.rencontrer(ship2);
  cout << "Apres la rencontre :" << endl;
  cout << ship1 << endl;
  cout << ship2 << endl;
}

int main()
{
  // Test de la partie 1
  cout << "===== Test de la partie 1 =====" << endl << endl;

  // Un bateau pirate 0,0
  Pirate ship1(0, 0, JollyRogers);
  cout << ship1 << endl;

  // Un bateau marchand en 25,0
  Marchand ship2(25, 0, CompagnieDuSenegal);
  cout << ship2 << endl;

  cout << "Distance : " << distance(ship1, ship2) << endl;

  cout << "Quelques déplacements..." << endl;
  cout << "  en haut à droite :" << endl;
  // Se déplace de 75 unités à droite et 10 en haut
  ship1.avancer(75, 10);
  cout << ship1 << endl;

  cout << "  vers le bas :" << endl;
  ship1.avancer(0, -5);
  cout << ship1 << endl;

  cout << endl << "===== Test de la partie 2 =====" << endl << endl;

  cout << "Bateau pirate et marchand ennemis (trop loins) :" << endl;
  rencontre(ship1, ship2);

  cout << endl << "Bateau pirate et marchand ennemis (proches) :" << endl;
  ship1.avancer(-40, -2);
  ship2.avancer(10, 2);
  rencontre(ship1, ship2);

  cout << endl << "Deux bateaux pirates ennemis intacts (proches) :" << endl;
  Pirate ship3(33, 8, CompagnieDOstende);
  rencontre(ship1, ship3);

  cout << endl << "Bateaux pirates avec dommages, ennemis :" << endl;
  rencontre(ship1, ship3);

  cout << endl << "Bateaux marchands ennemis :" << endl;
  Marchand ship4(21, 7, CompagnieDuSenegal);
  Marchand ship5(27, 2, CompagnieDOstende);
  rencontre(ship4, ship5);

  cout << endl << "Pirate vs Felon :" << endl;
  ship3.renflouer();
  Felon ship6(32, 10, CompagnieDuSenegal);
  rencontre(ship3, ship6);

  cout << endl << "Felon vs Pirate :" << endl;
  rencontre(ship6, ship3);

  return 0;
}
