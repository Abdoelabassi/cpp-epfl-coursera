#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  double x;                           // déclaration
  cout << "Entrez un nombre réel : "; // message
  cin  >> x;                          // lecture de x

  double resultat(0.0);

  // Expression 1
  cout << "Expression 1 : ";
  if (exp(x) == 1.0) /* Condition qui rend la division ci-dessous invalide.   *
                      * On pourrait bien sûr aussi écrire (x == 0.0),  mais   *
                      * nous avons ici voulu expliciter la raison de ce test. */
    { cout << "indéfinie" << endl; } 
  else {
    resultat = x / (1.0 - exp(x));
    cout << resultat << endl;
  }

  // Expression 2
  cout << "Expression 2 : ";
  if (   (x <= 0.0)  // condition qui empêche le calcul du log
      or (x == 1.0)) // condition qui empêche la division
    { cout << "indéfinie" << endl; }
  else {
      resultat = x * log(x) * exp( 2.0 / (x-1.0) ) ;
      cout << resultat << endl;
  }

  // Expression 3
  cout << "Expression 3 : ";
  if ((x*x - 8.0*x < 0.0) /* Condition rend la racine ci-dessous invalide.  *
                           * On pourrait bien sûr aussi écrire :            *
                           *              (x > 0.0) and (x < 8.0)           *
                           * mais nous avons ici voulu expliciter la raison *
                           * de ce test.                                    */
      or (x == 2.0)) /* Condition pour empêche la division.                *
                      * On pourrait bien sûr supprimer cette condition qui *
                      * est incluse dans la précédente, mais nous avons à  *
                      * nouveau voulu illustrer la démarche générale...    *
                      * ...laquelle peut ensuite être simplifiée.          */
    { cout << "indéfinie" << endl; }
  else {
      resultat = ( -x - sqrt(x*x - 8.0*x) ) / (2.0-x) ;
      cout << resultat << endl;
  }

  // Expression 4
  cout << "Expression 4 : ";
  if (x == 0.0) // pour pouvoir faire la division par x
    { cout << "indefinie" << endl; }
  else {
    resultat = x*x - 1.0/x; // calcul partiel
    if (resultat <= 0.0) // condition pour pouvoir prendre le log de cette expression
      { cout << "indefinie" << endl; }
    else {
      resultat = (sin(x) - x/20.0) * log(resultat); // calcul partiel
      if (resultat < 0.0) // condition pour prendre la racine de cette expression
        { cout << "indefinie" << endl; } 
      else {
        cout << sqrt(resultat) << endl;
      } 
    } 
  }
  return 0;
}
