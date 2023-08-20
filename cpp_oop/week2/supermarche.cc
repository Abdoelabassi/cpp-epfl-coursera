#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ======================================================================

class Article{


  public:
      Article(string name, double prix, bool en_action = false)
        : name(name), prix(prix), en_action(en_action)
        {}

      string getName()const {return name;}
      double getPrix()const {return prix;}
      bool isSolde()const {return en_action;}


  private:
     string name;
     double prix;
     bool en_action;

};

class Achat{
 
  public:
    Achat(Article const& article, unsigned int quantite = 1)
      : article(article), quantite(quantite)
      {}

    double prix() const{
      double prix = article.getPrix()*quantite;
      if (article.isSolde()){
        prix *= 0.5;
      }
      return prix;
    }

    void afficher() const{
      cout << article.getName() << " : " <<  article.getPrix() << " x " << quantite << " = " << prix() << " F " << endl;
      if (article.isSolde()){
        cout << "En action " << endl;
      }
    }

     private:
      const Article article;
      const unsigned int quantite;

};

class Caddie{

  public:
    void remplir(Article const& article, unsigned int quantite = 1){

      achats.push_back(Achat(article, quantite));

    }

    double total() const{
      double somme(0.0);

      for(auto const& achat : achats){
        achat.afficher();
        somme += achat.prix();
      }

      return somme;
    }

    private:
    vector<Achat> achats;

};

class Caisse{

  public:
    Caisse() : total(0.0){}
    void scanner(Caddie const& caddie){
      double montant = caddie.total();
      total += montant;

      cout << "------" << endl;
      cout << "Montant total: " << montant << " F " << endl;


    }

    void afficher(){
      cout << total << " F " << endl;
    }





private:
  double total;

};


int main()
{
  // Les articles vendus dans le supermarché
  Article choufleur ("Chou-fleur extra"      ,  3.50 );
  Article roman     ("Les malheurs de Sophie", 16.50, true );
  Article camembert ("Cremeux 100%MG"        ,  5.80 );
  Article cdrom     ("C++ en trois jours"    , 48.50 );
  Article boisson   ("Petit-lait"            ,  2.50, true);
  Article petitspois("Pois surgeles"         ,  4.35 );
  Article poisson   ("Sardines"              ,  6.50 );
  Article biscuits  ("Cookies de grand-mere" ,  3.20 );
  Article poires    ("Poires Williams"       ,  4.80 );
  Article cafe      ("100% Arabica"          ,  6.90, true);
  Article pain      ("Pain d'epautre"        ,  6.90 );

  // Les caddies du supermarché, disons 3 ici
  vector<Caddie> caddies(3);

  // Les caisses du supermarché, disons 2
  vector<Caisse> caisses(2);

  // Les clients font leurs achats :
  // le second argument de la méthode remplir correspond à une quantité

  // remplissage du 1er caddie
  caddies[0].remplir(choufleur, 2);
  caddies[0].remplir(cdrom       );
  caddies[0].remplir(biscuits , 4);
  caddies[0].remplir(boisson  , 6);
  caddies[0].remplir(poisson  , 2);

  // remplissage du 2eme caddie
  caddies[1].remplir(roman        );
  caddies[1].remplir(camembert    );
  caddies[1].remplir(petitspois, 2);
  caddies[1].remplir(poires    , 2);

  // remplissage du 3eme caddie
  caddies[2].remplir(cafe     , 2);
  caddies[2].remplir(pain        );
  caddies[2].remplir(camembert, 2);

  // Les clients passent à la caisse :
  caisses[0].scanner(caddies[0]);
  cout << "=========================================" << endl;
  caisses[0].scanner(caddies[1]);
  cout << "=========================================" << endl;
  caisses[1].scanner(caddies[2]);
  cout << "=========================================" << endl;

  // Affichage du résultat des caisses
  cout << "Résultats du jour :" << endl;
  for (size_t i(0); i < caisses.size(); ++i) {
    cout << "Caisse " << i+1 << " : " ;
    caisses[i].afficher();
    cout << endl;
  }

  return 0;
}
