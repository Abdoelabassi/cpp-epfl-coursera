#include <iostream>


using namespace std;


int demander_annee(){
    int annee;

    do{
        cout << "Entrez une annee (1583-4000) :";
        cin >> annee;

    }while(not(annee>=1583 and annee<=4000));

    return annee;
}

void affiche_date(int annee, int nombre){
    if(nombre >= 22 && nombre <=56){
        if(nombre <= 31){
            cout << "Date de Paques en " << annee << " : ";
            cout << nombre << " mars ";
        }else if(nombre >= 32){
            int nombre_jour = nombre;
            nombre_jour -= 31;
            cout << "Date de Paques en " << annee << " : ";
            cout << nombre_jour << " avril ";
        }
    }
}

int main(){











    return 0;
}