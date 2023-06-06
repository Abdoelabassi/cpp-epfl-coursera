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


int main()
{
    vector<int> tab {2,3,0,0,4};

    int max_somme = somme_consecutifs_max(tab);

    cout << "somme maximale des elements consecutifs " << max_somme << endl;

}