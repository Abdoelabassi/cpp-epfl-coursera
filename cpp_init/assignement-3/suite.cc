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
   */
   while(debut <= fin){
     int n = debut;
     int n_rep = 0;
     while(n != 0){
       if(n%3 == 0){
         n += 4;
       }else if(n%4 == 0){
         n /=2;
       }else{
         n -= 1;
       }
       n_rep++;
     }
     cout << debut << "->" << n_rep << endl;
     debut++;
   }


  /*******************************************
   * Ne rien modifier apres cette ligne.
   *******************************************/

  return 0;
}
