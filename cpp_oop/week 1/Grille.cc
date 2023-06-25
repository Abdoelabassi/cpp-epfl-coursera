#include <iostream>
#include <vector>
#include <string>
#include <array>

using namespace std;

enum Coleur {vide, rouge, jaune};

typedef  array<array<Coleur,7>, 6> Grille;


void initilise(Grille &grille){
    for(auto &ligne: grille){
        for(auto &kase: ligne){
            kase = vide; // *case* mot reserve par C++
        }
    }
}

void affiche(Grille const &grille){
    cout << endl;
    for (auto ligne: grille){
        cout << " |";
        for (auto kase: ligne){
            if(kase == vide){
                cout << ' ';
            }else if(kase == rouge ){
                cout << "O";
            }else{
                cout << "X";
            }
            cout << "|";
        }
        cout << endl;
    }
    cout << "=";
    for(size_t i(1); i <= grille[0].size(); ++i){
        cout << "=" << i;
    }
    cout << "==";
    cout << endl << endl;
}

void joue(Grille& grille, int colonne, Coleur coleur){

    // en parcourt le colonne en partent du bas
    size_t ligne = grille.size() - 1;
    bool pleine(false);
    //.. jusqu'a trouver une case vide
    // jusqu'en haut de la colonne si le colonne est plain
    while( (not pleine)  and ( grille[ligne][colonne] != vide)){
        if(ligne == 0){
            pleine = true;
        }else{
        --ligne;
        }
    }

    grille[ligne][colonne] = coleur;
}




int main(){

    Grille grille;

    initilise(grille);
    affiche(grille);

    joue(grille, 2, rouge);
    affiche(grille);






    return 0;
}