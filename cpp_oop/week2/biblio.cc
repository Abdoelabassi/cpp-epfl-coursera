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

class Auteur
{

    public:
        Auteur(string nom, bool primee = false) : nom(nom), primee(primee){}

        Auteur(Auteur const&) = delete;

        string getNom() const {return nom;}
        bool getPrix(){
                if(primee){
                    return true;
                }else{
                    return false;
                }
        }





    private:
        string nom;
        bool primee;

};

class Oeuvre
{

    public:
        Oeuvre(string titre, Auteur &auteur, string langue)
        : titre(titre), auteur(&auteur), langue(langue)
        {}
        Oeuvre(Oeuvre const&) = delete;

        ~Oeuvre() { cout << "L'oeuvre \"" << titre << ", " << (*auteur).getNom() << ", en " << langue << "\" n'est plus disponible." << endl; }


        string getTitre() const {return titre;}

        Auteur& getAuteur() const {return (*auteur);}

        string getLangue() const {return langue;}

        void affiche(){
            cout << titre << ", "  << (*auteur).getNom() << ", en " << langue << endl;
        }
        
    private:
        string titre;
        Auteur* auteur;
        string langue;

};

class Exemplaire
{

    public:
        Exemplaire(Oeuvre &oeuvre)
            : oeuvre(oeuvre)
        {
        cout << "Nouvel exemplaire de : ";
        oeuvre.affiche();
        
        }

        Exemplaire(Exemplaire const& exemplaire)
            : oeuvre(exemplaire.oeuvre)
        {
            cout << "Copie d'un exemplaire de : " << exemplaire.oeuvre.getTitre() << ", " << exemplaire.oeuvre.getAuteur().getNom() << ", " << " en " << exemplaire.oeuvre.getLangue() << endl;
        }

       
        Oeuvre& getOeuvre() const {

            return oeuvre;

        }

        void affiche(){
            cout << "Exemplaire de : " << oeuvre.getTitre() << ", " << oeuvre.getAuteur().getNom() << ", en " << oeuvre.getLangue();
        }

        ~Exemplaire()
        {
        cout << "Un exemplaire de \"" << oeuvre.getTitre() << " , " << oeuvre.getAuteur().getNom() << ", en " << oeuvre.getLangue() << "\" a été jeté !\n";
        }





    private:
        Oeuvre& oeuvre;

};

class Bibliotheque
{

    public:
        Bibliotheque(string nom)
            : nom(nom)
        {
            cout << "La bibliothèque " << nom << " est ouverte !" << endl;
        }

        string getNom() const {return nom;}

        void stocker(Oeuvre &oeuvre, int n = 1){

            for (int i = 0; i < n; ++i){
               Exemplaire* livre = new Exemplaire(oeuvre);
               exemplaire.push_back(livre);
            }

        }

        void lister_exemplaires(string langue = ""){

           for(unsigned int i = 0; i < exemplaire.size();++i){
                if(langue == "" || langue == exemplaire[i]->getOeuvre().getLangue()){
                    exemplaire[i]->affiche();
                    cout << "\n";
                }
           }

        }

        int compter_exemplaires(Oeuvre const& oeuvre){

            int count(0);

            for(unsigned int i=0; i < exemplaire.size();++i){
                if (exemplaire[i]->getOeuvre().getAuteur().getNom() == oeuvre.getAuteur().getNom() && exemplaire[i]->getOeuvre().getTitre() == oeuvre.getTitre()){

                    count++;

                }
            }

            return count;
            
        }

        void afficher_auteurs(bool primee = false){

             if (primee == true)
        {
            for (int i = 0; i < exemplaire.size(); i++)
            {
                if (exemplaire[i]->getOeuvre().getAuteur().getPrix() == true)
                {
                    cout << exemplaire[i]->getOeuvre().getAuteur().getNom() << endl;
                }
            }
        }
        else
        {
            for (int i = 0; i < exemplaire.size(); i++)
            {
                cout << exemplaire[i]->getOeuvre().getAuteur().getNom() << endl;
            }
        }

            
        }

        ~Bibliotheque()
        {
            cout << "La bibliothèque " << nom << " ferme ses portes," << endl << "et détruit ses exemplaires :" << endl;
            for (int i = 0; i < exemplaire.size(); i++)
            {
            exemplaire[i]->~Exemplaire();
            }
        }




    private:
        string nom;
        vector<Exemplaire*> exemplaire;

};

/*******************************************
 * Ne rien modifier apres cette ligne.
 *******************************************/
int main()
{
  Auteur a1("Victor Hugo"),
         a2("Alexandre Dumas"),
         a3("Raymond Queneau", true);

  Oeuvre o1("Les Misérables"           , a1, "français" ),
         o2("L'Homme qui rit"          , a1, "français" ),
         o3("Le Comte de Monte-Cristo" , a2, "français" ),
         o4("Zazie dans le métro"      , a3, "français" ),
         o5("The Count of Monte-Cristo", a2, "anglais" );

  Bibliotheque biblio("municipale");
  biblio.stocker(o1, 2);
  biblio.stocker(o2);
  biblio.stocker(o3, 3);
  biblio.stocker(o4);
  biblio.stocker(o5);

  cout << "La bibliothèque " << biblio.getNom()
       << " offre les exemplaires suivants :" << endl;
  biblio.lister_exemplaires();

  const string langue("anglais");
  cout << " Les exemplaires en "<< langue << " sont :" << endl;
  biblio.lister_exemplaires(langue);

  cout << " Les auteurs à succès sont :" << endl;
  biblio.afficher_auteurs(true);

  cout << " Il y a " << biblio.compter_exemplaires(o3) << " exemplaires de "
       << o3.getTitre() << endl;

  return 0;
}
