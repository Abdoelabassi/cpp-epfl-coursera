#include <iostream>
using namespace std;

int main() {
  cout << "Entrez un réel : " ;  // demande à l'utilisateur d'entrer un réel
  double x ;                     // déclaration de la variable x
  cin >> x ;                     // enregistre la réponse dans x

  if ( (x >= -1.0) and (x < 1.0) ) {
      cout << "x appartient à I" << endl;
  } else {
      cout << "x n'appartient pas à I" << endl;
  }

  return 0;
}
