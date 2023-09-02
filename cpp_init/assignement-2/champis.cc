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

    cout << "Pensez à  un champignon : amanite tue-mouches, pied bleu, girolle," << endl
       << "cèpe de Bordeaux, coprin chevelu ou agaric jaunissant." << endl << endl;
  
    cout << "Est-ce que votre champignon a un chapeau convexe (1 : oui, 0 : non) ? ";
	cin >> qst1;
	cout << endl;
	if (qst1 == 0)
	{
		cout << "Est - ce que votre champignon a des lamelles(1 : oui, 0 : non) ?";
		cin >> qst2;
		cout << endl;
		if (qst2 == 0)
		{
			cout << "==> Le champignon auquel vous pensez est ";
			cout << "le cèpe de Bordeaux";
		}
		else
		{
			cout << "Est-ce que votre champignon a un anneau (1 : oui, 0 : non) ? ";
			cin >> qst3;
			cout << endl;
			if (qst3 == 1)
			{
				cout << "==> Le champignon auquel vous pensez est ";
				cout << "le coprin chevelu";
			}
			else
			{
				cout << "==> Le champignon auquel vous pensez est ";
				cout << "la girolle";
			}
		}
	}
	else
	{
		cout << "Est-ce que votre champignon vit en forêt (1 : oui, 0 : non) ? ";
		cin >> qst4;
		cout << endl;
		if (qst4 == 1)
		{
			cout << "Est-ce que votre champignon a un anneau (1 : oui, 0 : non) ? ";
			cin >> qst3;
			cout << endl;
			if (qst3 == 1)
			{
				cout << "==> Le champignon auquel vous pensez est ";
				cout << "l'amanite tue-mouches";
			}
			else
			{
				cout << "==> Le champignon auquel vous pensez est ";
				cout << "le pied bleu";
			}
		}
		else
		{
			cout << "==> Le champignon auquel vous pensez est ";
			cout << "l'agaric jaunissant";
		}
	}








    return 0;
}