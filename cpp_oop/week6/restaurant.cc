#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

/*****************************************************
  * Compléter le code à partir d'ici
 *****************************************************/
class Produit
{
  protected:
    string nom;
    string unite;
  public:
    Produit(string nom_, string unite_ = ""): nom(nom_), unite(unite_)
    {}
    virtual ~Produit(){}
    string getNom() const { return nom;}
    string getUnite() const { return unite;}
    string toString() const { return nom;}

};

class Ingredient
{
  protected:
    double quantite;
    Produit p;
  public:
    Ingredient(const Produit &p_, double quantite_): p(p_), quantite(quantite_)
    {}
    const Produit& getProduit() const { return p;}
    double getQuantite() const { return quantite;}
    void descriptionAdaptee() const
    {
      cout << quantite << p.getUnite() << " de " << p.toString();
    }

  

};

class Recette
{
  protected:
    unsigned int nb_Fois;
    string nom;
    vector<Ingredient> ingredients;

  public:
    Recette(){}
    Recette(string nom_, unsigned int n_fois = 1): nom(nom_), nb_Fois(n_fois)
    {}

    void ajouter(const Produit& p, double quantite)
    {
      quantite *= nb_Fois;
      ingredients.push_back(Ingredient(p, quantite));
    }
    Recette adapter(double n)
    {
      nb_Fois *= n;
      return Recette(nom, nb_Fois);
    }

    void toString() const
    {
      cout << "Recette " << nom << " x " << nb_Fois << endl;
      for (size_t i(0); i < ingredients.size(); i++)
      {
        cout << i;
        ingredients[i].descriptionAdaptee();
      }
    }


};

class ProduitCuisine: public Produit
{
  protected:
    string nom;
    string unite;
    Recette r;
  public:
    ProduitCuisine(string nom_, string unite_ = "portion(s)"): Produit(nom_, unite_){}

    void ajouterARecette(const Produit& produit, double quantite)
    {
      r.ajouter(produit, quantite);
    }
    const ProduitCuisine* adapter(double n)
    {
      

    }


};
/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/
void afficherQuantiteTotale(const Recette& recette, const Produit& produit)
{
  string nom = produit.getNom();
  cout << "Cette recette contient " << recette.quantiteTotale(nom)
       << " " << produit.getUnite() << " de " << nom << endl;
}

int main()
{
  // quelques produits de base
  Produit oeufs("oeufs");
  Produit farine("farine", "grammes");
  Produit beurre("beurre", "grammes");
  Produit sucreGlace("sucre glace", "grammes");
  Produit chocolatNoir("chocolat noir", "grammes");
  Produit amandesMoulues("amandes moulues", "grammes");
  Produit extraitAmandes("extrait d'amandes", "gouttes");

  ProduitCuisine glacage("glaçage au chocolat");
  // recette pour une portion de glaçage:
  glacage.ajouterARecette(chocolatNoir, 200);
  glacage.ajouterARecette(beurre, 25);
  glacage.ajouterARecette(sucreGlace, 100);
  cout << glacage.toString() << endl;

  ProduitCuisine glacageParfume("glaçage au chocolat parfumé");
  // besoin de 1 portions de glaçage au chocolat et de 2 gouttes
  // d'extrait d'amandes pour 1 portion de glaçage parfumé

  glacageParfume.ajouterARecette(extraitAmandes, 2);
  glacageParfume.ajouterARecette(glacage, 1);
  cout << glacageParfume.toString() << endl;

  Recette recette("tourte glacée au chocolat");
  recette.ajouter(oeufs, 5);
  recette.ajouter(farine, 150);
  recette.ajouter(beurre, 100);
  recette.ajouter(amandesMoulues, 50);
  recette.ajouter(glacageParfume, 2);

  cout << "===  Recette finale  =====" << endl;
  cout << recette.toString() << endl;
  afficherQuantiteTotale(recette, beurre);
  cout << endl;

  // double recette
  Recette doubleRecette = recette.adapter(2);
  cout << "===  Recette finale x 2 ===" << endl;
  cout << doubleRecette.toString() << endl;

  afficherQuantiteTotale(doubleRecette, beurre);
  afficherQuantiteTotale(doubleRecette, oeufs);
  afficherQuantiteTotale(doubleRecette, extraitAmandes);
  afficherQuantiteTotale(doubleRecette, glacage);
  cout << endl;

  cout << "===========================\n" << endl;
  cout << "Vérification que le glaçage n'a pas été modifié :\n";
  cout << glacage.toString() << endl;

  return 0;
}
