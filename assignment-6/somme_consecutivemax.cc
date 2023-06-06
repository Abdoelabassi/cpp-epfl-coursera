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
    int maxlignes;

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
     
}