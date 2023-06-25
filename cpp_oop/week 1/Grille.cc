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

bool joue(Grille& grille, int colonne, Coleur coleur){

    // si le numero de colonne n'est pas valide. le coup n'est pas valide
    if(colonne >= grille[0].size()){
        return false;
    }


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

    // si on'est pas a arrivee jusau'en haut de la colonne, one remplit la case vide trouvee
    // sinon c'est que la colonne est plaine, et le coup ne'est pas valide
    if (not pleine){
        grille[ligne][colonne] = coleur;
        return true;
    }else{
        return false;
    }
}

void demande_de_joue(Grille &grille, Coleur coleur){



    bool valide;
    if(coleur == jaune){
            cout << "Joueur X: " << " Entrez un numero de colonne " << endl;
        }else{
            cout << "Joueur O: " << " Entrez un numero de colonne" << endl;
        }

        do{
        size_t colonne;
        cin >> colonne;
        --colonne;

        valide = joue(grille, colonne, coleur);
        if(not valide){
            cout << "> Ce coup n'est pas valide " << endl;
        }

        }while(not valide);
}




int main(){

    Grille grille;

    initilise(grille);
    affiche(grille);
    Coleur coleur(jaune);

 

   






    return 0;
}