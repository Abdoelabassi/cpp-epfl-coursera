#include <iostream>


using namespace std;


int main(){

// The "cèpe de Bordeaux" is the only one to have pores ("tubes" in French), the
// other mushrooms having gills ("lamelles" in French).
// Both "coprin chevelu" and "agaric jaunissant" grow in meadows ("dans les prés" in
// French), while all the other mushrooms grow in the woods ("en forêt" in French).
// The only mushrooms to have a convex cap ("chapeau convexe") are the "agaric
// jaunissant", the "amanite tue-mouches" and the "pied bleu".
// And the only mushrooms to have a annulus/ring ("anneau") are the "agaric jaunis-
// sant", the "amanite tue-mouches" and the "coprin chevelu".

    bool qst1;
    bool qst2;
    bool qst3;
    bool qst4;

    cout << "Pensez Ã  un champignon : amanite tue-mouches, pied bleu, girolle," << endl
       << "cÃ¨pe de Bordeaux, coprin chevelu ou agaric jaunissant." << endl << endl;
  
    cout << "Est-ce que votre champignon a des lamelles (1 : oui, 0 : non) ? ";
    cin >> qst1;
    cout << "Est-ce que votre champignon a un anneau (1 : oui, 0 : non) ? ";
    cin >> qst2;
    cout << "Est-ce que votre champignon a un chapeau convexe (1 : oui, 0 : non) ? ";
    cin >> qst3;
    cout << "Est-ce que votre champignon vit en forÃªt (1 : oui, 0 : non) ? ";
    cin >> qst4;

    cout << "==> Le champignon auquel vous pensez est ";

    cout << "l'agaric jaunissant";
    cout << "l'amanite tue-mouches";
    cout << "le cÃ¨pe de Bordeaux";
    cout << "le coprin chevelu";
    cout << "la girolle";
    cout << "le pied bleu";








    return 0;
}