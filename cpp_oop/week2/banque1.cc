#include <iostream>
#include <string>
#include <vector>
using namespace std;


// global vars 
typedef std::vector<double> Taux;



// Compte

class Compte{

  private:
    double soldeprive;
    double soldeEparagne;

  public:
    Compte(double solde1, double solde2)
      : soldeprive(solde1), soldeEparagne(solde2)
      {
        std::cout << "compte remplee" << std::endl;
      }
    ~Compte(){std::cout << "What a account!." << std::endl;}

    Compte(Compte const& compte)
      : soldeprive(compte.soldeprive), soldeEparagne(compte.soldeEparagne)
      {
        std::cout << "account duplicated!" << std::endl;
      }

      double getSoldePrive(){
        return soldeprive;
      }

      double getSoldeEparagne(){
        return soldeEparagne;
      }

};



// Client

class Client{

      private:
          std::string name;
          std::string ville;

      public:
          Client(std::string name, std::string ville)
            : name(name), ville(ville)
            {
              std::cout << "Client cree" << std::endl;
            }
          ~Client(){std::cout << " client departed " << std::endl;}

          Client(Client const& client)
            : name(client.name), ville(client.ville)
            {
              std::cout << "just copied you !." << std::endl;
            }

          // Cette fonction affiche les données d'un client
          void afficherClient(double solde1, double solde2) {
                Compte compte(solde1, solde2);
                cout << "Client " << name << " de " << ville << endl;
                cout << "   Compte courant : " << compte.getSoldePrive() << " francs" << endl;
                cout << "   Compte épargne : " << compte.getSoldeEparagne() << " francs" << endl;
          }

          std::string getName(){
            return name;
          }

          std::string getVille(){
            return ville;
          }



};

class Billet{

    private:
      double taux1;
      double taux2;

    public:
      Billet(double taux1, double taux2)
        : taux1(taux1), taux2(taux2)
        {
          std::cout << "definit les taux d'interet" << std::endl;
        }
      ~Billet(){std::cout << "fin de calcule" << std::endl;}

      Billet(Billet const& billet)
        : taux1(billet.taux1), taux2(billet.taux2)
        {
          std::cout << "billet duplique" << std::endl;
        }

        double getPTaux(){
          return taux1;
        }

        double getDTaux(){
          return taux2;
        }

        

        // Cette fonction ajoute les intérêts au solde d'un compte
        Taux bouclerCompte(Compte &compte, Billet &taux) {

                Taux Int;
                
                double interet1 = taux.getPTaux() * compte.getSoldePrive();
                interet1 += compte.getSoldePrive();
                Int.push_back(interet1);
                double interet2 = taux.getDTaux()* compte.getSoldeEparagne();
                interet2 += compte.getSoldeEparagne();
                Int.push_back(interet2);
                return Int;
                
        }


};










int main()
{
  // Données pour tous les comptes privés (taux d'intérêt) :
  double taux1(0.01);
  // Données pour tous les comptes d'épargne (taux d'intérêt) :
  double taux2(0.02);

  Billet Taxes(0.01, 0.02);
  // Données pour le premier client (nom et ville) :
  Client client1("Pedro", "Geneve");
  // Données pour le compte privé du premier client (solde) :
  // Données pour le compte d'épargne du premier client (solde) :
  Compte compte1(1000.0, 2000.0);
  // Données pour le deuxième client (nom et ville) :
  Client client2("Alexandra", "Lausanne");
  // Données pour le compte privé du deuxième client (solde) :
  // Données pour le compte d'épargne du deuxième client (solde) :
  Compte compte2(3000.0, 4000.0);

  std::cout << "Données avant le bouclement des comptes :" << std::endl;
  // Afficher les données du premier client :
  client1.afficherClient(compte1.getSoldePrive(), compte1.getSoldeEparagne());
  // Afficher les données du deuxième client:
  client2.afficherClient(compte2.getSoldePrive(), compte2.getSoldeEparagne());

  // Bouclement du compte privé et epargne du premier client:
  Taux soldePremierClient = Taxes.bouclerCompte(compte1, Taxes);
  // Bouclement du compte privé et epargne du deuxième client:
  Taux soldeDeuxiemeClient = Taxes.bouclerCompte(compte2, Taxes);

  cout << "Données apres le bouclement des comptes :" << endl;
  // Afficher les données du premier client:
  client1.afficherClient(soldePremierClient[0], soldePremierClient[1]);
  // Afficher les données du deuxième client:
  client2.afficherClient(soldeDeuxiemeClient[0], soldeDeuxiemeClient[1]);

  return 0;
}
