#include <iostream>
#include <vector>


using namespace std;

vector<vector<double>> lire_matrice()
{
    unsigned int lignes(0);
    unsigned int colonnes(0);
    cout << "Saisie d'une matrice :" << endl;
    do{
    cout << "Nombre des lignes: ";
    cin >> lignes;
    }while(lignes < 1);
    do{
    cout << "Nombre des colonnes: ";
    cin >> colonnes;
    }while(colonnes < 1);

    vector<vector<double>> M(lignes, vector<double> (colonnes));


    for(unsigned int i(0); i < lignes; ++i ){
        for (unsigned int j(0); j < colonnes; ++j ){
            cout << "M[" << i+1 << "," << j+1 << "] = ";
            cin >> M[i][j];
        }
    }

    return M;

}

vector<vector<double>> multiplication(const vector<vector<double>>& M1, const vector<vector<double>>& M2){


    double lignes = M1[0].size();
    double colonnes = M2[1].size();

    
    vector<vector<double>> matrice(lignes, vector<double> (colonnes));

    if(M1[0].size() == M2.size()){
        for(size_t i(0); i < M1.size(); ++i ){
            for (size_t j(0); j < M2[0].size(); ++j ){
                for(size_t k(0); k < M2.size(); ++k ){
                    matrice[i][j] += M1[i][k]*M2[k][j];
                }
            } 
        }
    }


    return matrice;



}

void affiche_matrice(const vector<vector<double>>& M ){

    for(auto ligne: M){
        for(auto elm: ligne){

            cout << elm << " ";


        }

        cout << endl;
    }
}

int main()
{

    const vector<vector<double>> M1(lire_matrice());

    const vector<vector<double>> M2(lire_matrice());

    const vector<vector<double>> matrice = multiplication(M1, M2);

    affiche_matrice(matrice);

    











    return 0;
}