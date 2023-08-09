#include <iostream>
#include <string>
#include <vector>


using namespace std;

int somme_consecutifs_max(vector<int> tab)
{
    int somme(0);
    int somme_max(0);

    for (auto elm: tab)
    {
        if (elm > 0)
        {
            somme += elm;
            if (somme_max < somme){
                somme_max = somme;
            }
        }
        else {
            somme = 0;
        }
    }

    return somme_max;
}

vector<size_t> lignes_max(vector<vector<int>> tab)
{
    vector<size_t> lignesmax;
    vector<int> somme_stock;
    int ligne_max;
    int maxlignes(0);

    for(size_t i(0); i < tab.size(); ++i )
    {
        ligne_max = somme_consecutifs_max(tab[i]);
        somme_stock.push_back(ligne_max);

        if (maxlignes < ligne_max)
        {
            maxlignes = ligne_max;
        }
    }
    for (size_t i(0); i < somme_stock.size(); ++i )
    {
        if(somme_stock[i] == maxlignes )
        {
            lignesmax.push_back(i);
        }
    }

    return lignesmax;
}

vector<vector<int>> tranches_max(vector<vector<int>> tab)
{
    vector<vector<int>> maxTranches;
    vector<size_t> maxlignes = lignes_max(tab);

    for(auto ind: maxlignes)
    {
        maxTranches.push_back(tab[ind]);
    }

    return maxTranches;
}


int main()
{
     cout << somme_consecutifs_max({ 0, 2, 2, 0 }) << endl;
	cout << somme_consecutifs_max({ 2, 3, 0, 0, 4 }) << endl;
	cout << somme_consecutifs_max({ 4, 0, 2, 3 }) << endl;
	cout << somme_consecutifs_max({ 0, 0, 0, 0, 0 }) << endl;
	cout << endl;

	vector<vector<int>> tableau = {
		{2, 1, 0, 2},
		{0, 1, 0, 3},
		{1, 3, 0, 0},
		{0, 2, 2, 0}
	};
	vector<size_t> resultant = lignes_max(tableau);
	
	bool virg = false;
	cout << "{";
	for (auto element : resultant) {
		if (virg)
			cout << ", ";
		else
			virg = true;
		cout << element;
	}
	cout << "}" << endl;
	cout << endl;

	tableau = {
		{2, 1, 0, 2, 0, 3, 2},
		{0, 1, 0, 7, 0},
		{1, 0, 1, 3, 2, 0, 3, 0, 4},
		{5, 0, 5},
		{1, 1, 1, 1, 1, 1, 1}
	};
	
	vector<vector<int>> res = tranches_max(tableau);
	for (auto ligne : res) {
		virg = false;
		cout << "{";
		for (auto element : ligne) {
			if (virg)
				cout << ", ";
			else
				virg = true;
			cout << element;
		}
		cout << "}" << endl;
	}
cout << endl;
     
}