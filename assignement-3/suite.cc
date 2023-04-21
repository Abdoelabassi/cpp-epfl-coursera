#include <iostream>
using namespace std;

int main()
{
  int debut(0);
  do {
    cout << "de (>= 1) ? ";
    cin >> debut;
  } while (debut < 1);

  int fin(0);
  do {
    cout << "a (>= " << debut << ") ? ";
    cin >> fin;
  } while (fin < debut);

  /*******************************************
   * Completez le programme a partir d'ici.
   *******************************************/
    int i(2);

    while(i >= debut && i <= fin){
      if (i % 3 == 0){
        i += 4;
      }
      else if (i % 4 == 0){
        i /= 2;
      }
      else{
        i--;
      }

      if (i == 0){
        break;
      }

      i++;

      cout << i << "->" << debut << endl;
    }

  /*******************************************
   * Ne rien modifier apres cette ligne.
   *******************************************/

  return 0;
}
