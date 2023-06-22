#include <iostream>

using namespace std;

double* selecteur(){

     double valeur1(0), valeur2(0), valeur3(0);

    double* choix(&valeur1);

    do{
        cout << "Entrez une valeur entre 1 et 3: ";
        cin >> *choix;
        cout << endl;
        cout << "Vous avez choisez: " << *choix << endl;

    }while(*choix <= 1 or *choix >= 3 );

    return choix;
}





int main()
{

   








    return 0;
}