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
    ~Produit(){}
    virtual const Produit* adapter(double n) const
    {
      return this;
    }
    virtual double quantiteTotale(const string& nomProduit) const
    {
      if(this->getNom() == nomProduit) return 1;
      else return 0;
    }
    string getNom() const { return nom;}
    string getUnite() const { return unite;}
    virtual string toString() const { return nom;}

};

class Ingredient
{
  private:
    const Produit& p;
    double quantite;
   
  public:
    Ingredient(Produit const& p_, double quantite_): p(p_), quantite(quantite_)
    {}
    const Produit& getProduit() const { return p;}
    double getQuantite() const { return quantite;}
    string descriptionAdaptee() const
    {
      string tostring = to_string(quantite) + " " + p.getUnite() + " de " + p.adapter(quantite)->toString();
      return tostring;
    }
    double quantiteTotale(const string& nomProduit) const
    {
      return quantite * (p.quantiteTotale(nomProduit));
    }

  

};

class Recette
{
  private:
    string nom;
    double nbFois_;
    vector<Ingredient*> ingredients;

  public:
    Recette(string nom_, double n_fois = 1): nom(nom_), nbFois_(n_fois)
    {}

    void ajouter(const Produit& p, double quantite)
    {
      Ingredient* ingre = new Ingredient(p, quantite * nbFois_);
      ingredients.push_back(ingre);
    }
    Recette adapter(double n) const
    {
      Recette r(nom, nbFois_ * n);
      for (size_t i(0); i < ingredients.size(); i++)
      {
        r.ajouter(ingredients[i]->getProduit(), ingredients[i]->getQuantite() / nbFois_);
      }

      return r;
    }

    string toString() const
    {
      string tostring;
      int nfois = (int)nbFois_;
      string q = "\"";
      tostring = "Recette " + q +  nom + q + " x " + to_string(nfois) + ":\n";
      for (size_t i(0); i < ingredients.size(); ++i)
      {
        if (i == ingredients.size() - 1 ) tostring += to_string(i + 1) + ". " + ingredients[i]->descriptionAdaptee();
        else tostring += to_string(i + 1) + ". " +  ingredients[i]->descriptionAdaptee() + "\n";
      }
       return tostring;
    }
    virtual double quantiteTotale(const string& nomProduit) const
    {
      double sum(0);
      for (size_t i(0); i < ingredients.size(); i++){ sum += ingredients[i]->quantiteTotale(nomProduit);}
      return sum;
    }


};

class ProduitCuisine: public Produit
{
  private:
    Recette r;
  public:
    ProduitCuisine(string nom_, string unite_ = "portion(s)"): Produit(nom_, unite_), r(nom_){}

    void ajouterARecette(const Produit& produit, double quantite)
    {
      r.ajouter(produit, quantite);
    }
    const ProduitCuisine* adapter(double n) const override
    {
      ProduitCuisine* pc = new ProduitCuisine(nom);
      pc->r = r.adapter(n);
      return pc;      

    }
    string toString() const override
    {
      Produit p(this->getNom(), this->getUnite());
      string tostring = p.toString() + "\n" + r.toString();
      return tostring;
    }
    virtual double quantiteTotale(const string& nomProduit) const override
    {
      if (this->getNom() == nomProduit) return 1;
      else return r.quantiteTotale(nomProduit);
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
