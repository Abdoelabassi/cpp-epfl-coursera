#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*******************************************
 * Completez le programme a partir d'ici.
 *******************************************/
// Chaines de caractÃ¨res Ã  utiliser pour les affichages:
/*

Ã©tÃ© jetÃ©

d'un

n'est

L'oeuvre

bibliothÃ¨que

dÃ©truit

*/

class Auteur{

    public:
        Auteur(string nom, bool primee = false)
            : nom(nom), primee(primee)
        {

        }

        string getNom() const {return nom;}
        bool getPrix(){
            if(primee){
                return true;
            }

            return false;
        }





    private:
        string nom;
        bool primee;

};

class Oeuvre{

    public:
        Oeuvre(string titre, Auteur const& auteur, string langue)
            : titre(titre), auteur(auteur), langue(langue)
        {

        }

        string getTitre() const {return titre;}

        Auteur getAuteur() const {return auteur;}

        string getLangue() const {return langue;}

        void afficher(){
            cout << titre << auteur.getNom() << " en " << langue << endl;
        }

        ~Oeuvre()
        {
            cout << titre << auteur.getNom() << " en " << langue << " n'est plus disponible " << endl;
        }



    private:
        string titre;
        const Auteur auteur;
        string langue;

};

class Exemplaire{

    public:
        Exemplaire(Oeuvre const& oeuvre)
            : oeuvre(oeuvre)
        {
            cout << "Nouvel exemplaire de : "  << oeuvre.getTitre() << ", "  <<  oeuvre.getAuteur().getNom() << ", " << " en " << oeuvre.getLangue() << endl;
        }

        Exemplaire(Exemplaire const& exemplaire)
            : oeuvre(exemplaire.oeuvre)
        {
            cout << "Copie d'un exemplaire de :" << exemplaire.oeuvre.getTitre() << ", " << exemplaire.oeuvre.getAuteur().getNom() << ", " << " en " << exemplaire.oeuvre.getLangue() << endl;
        }

        ~Exemplaire()
        {
            cout << "Un exemplaire de " << oeuvre.getTitre() << ", " << oeuvre.getAuteur().getNom() << ", " << " en " << oeuvre.getLangue() << " a été jeté " << endl;
        }

        Oeuvre getOeuvre() const {

            return oeuvre;

        }

        void afficher(){
            cout << "Exemplaire de : " << oeuvre.getTitre() << ", " << oeuvre.getAuteur().getNom() << ", en " << oeuvre.getLangue();
        }






    private:
        Oeuvre oeuvre;

};

class Bibliotheque{

    public:
        Bibliotheque(string nom)
            : nom(nom)
        {
            cout << "La bibliothèque " << nom << " est ouvert ! " << endl;
        }

        string getNom() const {return nom;}

        void stocker(Oeuvre const& oeuvre, int n = 1){
            for (int i = 0; i < n; ++i){
                exemplaire.push_back(Exemplaire(oeuvre));
            }

        }

        void lister_exemplaires(string langue = ""){

            for (auto& exem: exemplaire){
                langue = exem.getOeuvre().getLangue();
                exem.afficher();
              
            }

        }

        int compter_exemplaires(Oeuvre const& oeuvre){

            int count(0);

            for(Exemplaire& exempl : exemplaire){
                if (exempl.getOeuvre().getAuteur().getNom() == oeuvre.getAuteur().getNom()){

                    count++;

                }
            }

            return count;
            
        }

        void afficher_auteurs(bool primee){

            if (primee){
                for(Exemplaire& ex: exemplaire){
                    cout << "Auteur " << ex.getOeuvre().getAuteur().getNom() << endl;

                }
            }


        }




    private:
        string nom;
        vector<Exemplaire> exemplaire;

};

/*******************************************
 * Ne rien modifier apres cette ligne.
 *******************************************/

int main()
{
  Auteur a1("Victor Hugo"),
         a2("Alexandre Dumas"),
         a3("Raymond Queneau", true);

  Oeuvre o1("Les MisÃ©rables"           , a1, "franÃ§ais" ),
         o2("L'Homme qui rit"          , a1, "franÃ§ais" ),
         o3("Le Comte de Monte-Cristo" , a2, "franÃ§ais" ),
         o4("Zazie dans le mÃ©tro"      , a3, "franÃ§ais" ),
         o5("The Count of Monte-Cristo", a2, "anglais" );

  Bibliotheque biblio("municipale");
  biblio.stocker(o1, 2);
  biblio.stocker(o2);
  biblio.stocker(o3, 3);
  biblio.stocker(o4);
  biblio.stocker(o5);

  cout << "La bibliothÃ¨que " << biblio.getNom()
       << " offre les exemplaires suivants :" << endl;
  biblio.lister_exemplaires();

  const string langue("anglais");
  cout << " Les exemplaires en "<< langue << " sont :" << endl;
  biblio.lister_exemplaires(langue);

  cout << " Les auteurs Ã  succÃ¨s sont :" << endl;
  biblio.afficher_auteurs(true);

  cout << " Il y a " << biblio.compter_exemplaires(o3) << " exemplaires de "
       << o3.getTitre() << endl;

  return 0;
}