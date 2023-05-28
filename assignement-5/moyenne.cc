#include <iostream>
#include <vector>

using namespace std;

double moyenne(vector<double> points)
{
    double somme(0);

    for(auto i: points){
        somme += i;
    }

    double avg = somme/points.size();
    return avg;
}

void ecart_a_moyenne(double avg, vector<double> points)
{
    vector<double> std;

    cout << "Details des notes: " << endl;

    for (size_t i(0); i < points.size(); ++i ){
        std.push_back(points[i] - avg);
        cout << (i+1) << " : "  << points[i] << " (" << std[i] << ")" << endl;
    }


}

int main()
{

    vector<double> tab(4,0);


    int i(1);

    for(auto &elv: tab){
        cout << "Entrez la note de l'eleve  " << i << " : ";
        cin >> elv;
        cout << endl;
        i++;
    }


    double avg = moyenne(tab);
    cout << "Moyenne de classe: " << avg << endl;

    ecart_a_moyenne(avg, tab);









    return 0;
}