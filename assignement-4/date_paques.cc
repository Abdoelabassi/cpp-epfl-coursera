#include <iostream>


using namespace std;


int demander_annee(){
    int annee;

    do{
        cout << "Entrez une annee (1583-4000) :";
        cin >> annee;

    }while(not(annee>1583 and annee<4000));

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

int date_paques(int annee){
    
    int siecle = annee/100;
    int p = (13 + 8*siecle)/25;
    int q = siecle/4;
    int M = (15 - p + siecle - q)% 30;
    int N = (4+siecle-q)%7;
    int d = (M+(19*(annee%19)))%30;
    int e = (2*(annee%4) + 4*(annee%7) + 6*d + N )%7;
    int day = e + d + 22;

    if((e==6) and ((d==29) or ((d==28) and (((11*(M+1))%30) < 19)))){
        
        day -= 7;

    }

    return day;


}

int main(){


    int a(0);
    int b(0);

    a = demander_annee();
    b = date_paques(a);
    affiche_date(a,b);

    











    return 0;
}