#include <iostream>
#include <string>
using namespace std;


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
                cout << "Client " << nom << " de " << ville << endl;
                cout << "   Compte courant : " << compte.getSoldePrive() << " francs" << endl;
                cout << "   Compte épargne : " << compte.getSoldeEparagne() << " francs" << endl;
          }



};








// Cette fonction ajoute les intérêts au solde d'un compte
double bouclerCompte(double solde, double taux) {
  double interets(taux * solde);
  double nouveauSolde(solde + interets);
  return nouveauSolde;
}

int main()
{
  // Données pour tous les comptes privés (taux d'intérêt) :
  double taux1(0.01);
  // Données pour tous les comptes d'épargne (taux d'intérêt) :
  double taux2(0.02);
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

  // Bouclement du compte privé du premier client:
  solde1PremierClient = bouclerCompte(solde1PremierClient, taux1);
  // Bouclement du compte d'épargne du premier client:
  solde2PremierClient = bouclerCompte(solde2PremierClient, taux2);
  // Bouclement du compte privé du deuxième client:
  solde1DeuxiemeClient = bouclerCompte(solde1DeuxiemeClient, taux1);
  // Bouclement du compte d'épargne du deuxième client:
  solde2DeuxiemeClient = bouclerCompte(solde2DeuxiemeClient, taux2);

  cout << "Données apres le bouclement des comptes :" << endl;
  // Afficher les données du premier client:
  afficherClient(nom1, ville1, solde1PremierClient, solde2PremierClient);
  // Afficher les données du deuxième client:
  afficherClient(nom2, ville2, solde1DeuxiemeClient, solde2DeuxiemeClient);

  return 0;
}
