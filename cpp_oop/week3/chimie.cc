#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Flacon
{
private:
  string nom;
  double volume;
  double pH;

public:
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/
  Flacon(string nom_, double volume_, double ph_) : nom(nom_), volume(volume_), pH(ph_)
  {}
  Flacon() = delete;

  friend ostream& etiquette(ostream& sortie);
  friend const Flacon operator+(Flacon f1, Flacon const& f2);

  ostream& etiquette(ostream& sortie) const;

  Flacon& operator+=(Flacon const& f);




};

ostream& Flacon::etiquette(ostream& sortie) const
{
  sortie << nom << " : " << volume << " ml, pH " << pH;
  return sortie;
}

ostream& operator<<(ostream& sortie, Flacon const& f)
{
  f.etiquette(sortie);
  return sortie;
}

const Flacon operator+(Flacon f1, Flacon const& f2)
{
  Flacon f("", 0.0, 0.0);
  f.nom = f1.nom + " + " + f2.nom;
  f.volume += f1.volume + f2.volume;
  f.pH += -log10((f1.volume*pow(10, -f1.pH) + f2.volume*pow(10, -f2.pH)) / (f1.volume + f2.volume) );

  return f;

}

Flacon& Flacon::operator+=(Flacon const& f)
{
  return *this = *this + f;
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void afficher_melange(Flacon const& f1, Flacon const& f2)
{
  cout << "Si je mélange " << endl;
  cout << "\t\"" << f1 << "\"" << endl;
  cout << "avec" << endl;
  cout << "\t\"" << f2 << "\"" << endl;
  cout << "j'obtiens :" << endl;
  cout << "\t\"" << (f1 + f2) << "\"" << endl;
}

int main()
{
  Flacon flacon1("Eau", 600.0, 7.0);
  Flacon flacon2("Acide chlorhydrique", 500.0, 2.0);
  Flacon flacon3("Acide perchlorique",  800.0, 1.5);

  afficher_melange(flacon1, flacon2);
  afficher_melange(flacon2, flacon3);

  return 0;

}
