#include <iostream>
#include <ctime>

// pour les nombres alÃ©atoires
#include <random>
#include <cstring> // strlen

using namespace std;

// ======================================================================
// Couleur au hasard
std::uniform_int_distribution<int> distribution;
std::default_random_engine generateur(time(NULL)); /* NOT using std::random_device since not
                                                    * all compilers seems to support it :-( */

char tirer_couleur()
{
  static const char* const couleurs = ".RGBCYM";
  static const int nb = strlen(couleurs) - 1;

  return couleurs[distribution(generateur,
                               std::uniform_int_distribution<int>::param_type {0, nb})];
}

// ======================================================================
char poser_question()
{
  char lu(' ');
  cout << "Entrez une couleur : ";
  cin >> lu;
  return lu;
}

// ---- prototype -------------------------------------------------------
bool couleur_valide(char c);

// ======================================================================
char lire_couleur()
{
  char lu(poser_question());
  while (not couleur_valide(lu)) {
    cout << "'" << lu << "' n'est pas une couleur valide." << endl;
    cout << "Les couleurs possibles sont : ., R, G, B, C, Y ou M." << endl;
    lu = poser_question();
  }
  return lu;
}

// ======================================================================
void afficher_couleurs(char c1, char c2, char c3, char c4)
{
  cout << ' ' << c1 << ' ' << c2 << ' ' << c3 << ' ' << c4;
}

// ======================================================================
void afficher(int nb, char c)
{
  while (nb-- > 0) {
    cout << c;
  }
}

// ---- prototype -------------------------------------------------------
void afficher_reponses(char c1, char c2, char c3, char c4,
                       char r1, char r2, char r3, char r4);

// ======================================================================
void afficher_coup(char c1, char c2, char c3, char c4,
                   char r1, char r2, char r3, char r4)
{
  afficher_couleurs(c1, c2, c3, c4);
  cout << " : ";
  afficher_reponses(c1, c2, c3, c4,
                    r1, r2, r3, r4);
  cout << endl;
}

// ======================================================================
void message_gagne(int nb_coups)
{
  cout << "Bravo ! Vous avez trouvÃ© en " << nb_coups << " coups." << endl;
}

// ======================================================================
void message_perdu(char c1, char c2, char c3, char c4)
{
  cout << "Perdu :-(" << endl;
  cout << "La bonne combinaison Ã©tait : ";
  afficher_couleurs(c1, c2, c3, c4);
  cout << endl;
}

/*****************************************************
 * ComplÃ©ter le code Ã  partir d'ici
 *****************************************************/

// ======================================================================
bool couleur_valide(char c)
{
  return ((c=='R') || (c=='G') || (c=='B') || (c=='M') 
  || (c=='Y') || (c=='.') || (c=='C') );
}

// ======================================================================
bool verifier(char coleur, char& secondColor, int& score)
{
  bool verify(false);
  if(coleur == secondColor){
    verify = true;
    score++;
    secondColor='u'; // set it to a char, that not in color list
  }

  return verify;
}

// ======================================================================
void apparier(char colorTest, char& colorTest1, char& colorTest2, char& colorTest3, int& score)
{
  bool test1(verifier(colorTest, colorTest1, score));
  if(!test1){
    bool test2(verifier(colorTest, colorTest2, score));
    if(!test2){
      verifier(colorTest, colorTest3, score);

    }
  }
}

// ======================================================================
void afficher_reponses(char c1, char c2, char c3, char c4,
                       char r1, char r2, char r3, char r4)
{
  int couleurCorrecte(0);
  int couleurIncorrecte(0);

  if(c1 == r1){
    couleurCorrecte++;
  }else{
    apparier(c1, r2, r3, r4, couleurIncorrecte);
  }


  if(c2 == r2){
    couleurCorrecte++;
  }else{
    apparier(c2, r1, r3, r4, couleurIncorrecte);
  }

  if(c3 == r3){
    couleurCorrecte++;
  }else{
     apparier(c3, r1, r2, r4, couleurIncorrecte);
  }

  if(c4 == r4){
    couleurCorrecte++;
  }else{
    apparier(c4, r1, r2, r3, couleurIncorrecte);
  }

  int faux = 4 - couleurCorrecte - couleurIncorrecte;
  afficher(couleurCorrecte, '#');
  afficher(couleurIncorrecte, '+');
  afficher(faux, '-');
}

// ======================================================================
bool gagne(char c1, char c2, char c3, char c4,
           char r1, char r2, char r3, char r4)
{
  return ((c1==r1) && (c2==r2) && (c3==r3) && (c4==r4) );
}

// ======================================================================
void jouer(int maxCoup = 8)
{
  char r1(tirer_couleur());
  char r2(tirer_couleur());
  char r3(tirer_couleur());
  char r4(tirer_couleur());
  char c1('u'),  c2('u'), c3('u'), c4('u');

  int minCoup(0);
  do{
    c1 = lire_couleur();
    c2 = lire_couleur();
    c3 = lire_couleur();
    c4 = lire_couleur();

    afficher_coup(c1,c2,c3,c4,r1,r2,r3,r4);

    minCoup++;
  }while(!gagne(c1,c2,c3,c4,r1,r2,r3,r4) && minCoup < maxCoup);

  if(gagne(c1,c2,c3,c4,r1,r2,r3,r4)){
    message_gagne(minCoup);
  }else{
    message_perdu(r1,r2,r3,r4);
  }
}

/*******************************************
 * Ne rien modifier aprÃ¨s cette ligne.
 *******************************************/

int main()
{
  jouer();
  return 0;
}