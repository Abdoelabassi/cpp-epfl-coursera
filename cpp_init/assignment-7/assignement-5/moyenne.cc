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

    vector<double> notes;

    double note(0);

    do{
        cout << "Entrez la note de l'eleve " << notes.size() + 1 << " : " << endl;
        cin >> note;
        if(note >= 0.0){
            notes.push_back(note);
        }
    }while(note >= 0.0);




    

    double avg = moyenne(notes);
    cout << "Moyenne de classe: " << avg << endl;

    ecart_a_moyenne(avg, notes);









    return 0;
}