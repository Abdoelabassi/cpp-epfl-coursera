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


unsigned int compte(Grille &grille, Coleur couleur, size_t ligne_depart, size_t colone_depart, int dir_ligne, int dir_colonne){

    unsigned int compteur(0);

    size_t ligne(ligne_depart);
    size_t colonne(colone_depart);

    while(grille[ligne][colonne] == grille[ligne][colonne] ){

        ++compteur;

        ligne += dir_ligne;
        colonne += dir_colonne;
    }


    return compteur;
}



bool est_ce_gangne(Grille &grille, Coleur couleur){

    

    for(size_t ligne(0); ligne < grille.size(); ++ligne ){
        for (size_t col(0); col < grille[ligne].size(); ++col){

            Coleur couleur_case(grille[ligne][col]);

            if (couleur_case == couleur){

            const size_t ligne_max(grille.size() - 4 );
            const size_t col_max(grille[ligne].size() - 4 );

            if(// en diagonale vers le haut et la droite
                (ligne >= 3 and col <= col_max and
                compte(grille, couleur, ligne, col,-1, +1 ) >= 4) or

              //horizontale vers la droite
                (col <= col_max and 
                compte(grille, couleur, ligne , col,0, +1) >= 4) or

              //en diagonale vers la bas a la droite
                ( ligne <= ligne_max and col <= col_max and 
                compte(grille, couleur, ligne, col,+1,+1) >= 4 )  or

              //verticalement verse le bas
                (ligne <= ligne_max and
                compte(grille, couleur, ligne, col,+1, 0) >= 4)){
                    return true;
                }
            }

        }
    }


    return false;
}

bool plein(const Grille &grille){

    for(auto kase: grille[0]){
        if(kase == vide){
            return false;
        }
    }

    return true;
}




int main(){

    Grille grille;

    initilise(grille);
    affiche(grille);
    Coleur coleur(jaune);

    bool gagne;

    do{
        demande_de_joue(grille, coleur);
        affiche(grille);

        gagne = est_ce_gangne(grille, coleur);

        if(coleur == jaune){
            coleur = rouge;
        }else{
            coleur = jaune;
        }
    }while(not gagne and not plein(grille));

    if (gagne) {
  // attention, on a change la couleur pour la couleur de l'autre joueur !
    cout << "Le joueur ";
    if (coleur == jaune) {
      cout << 'O';
    } else {
      cout << 'X';
    }
    cout << " a gagne' !" << endl;
  } else {
    cout << "Match nul !" << endl;
  }

 

   






    return 0;
}