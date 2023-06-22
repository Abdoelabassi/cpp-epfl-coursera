#include <iostream>
#include <string>


using namespace std;


 


int demander_nombre(int a, int b){

    if(a > b ){int tmp(b); b=a;a=tmp;}

    int res(0);

    do{
        cout << "Entrez une valeur entre " << a << " et " << b  << " : ";
        cin >> res;
    }while( (res < a) or (res > b) );

    return res;
}



void selecteur(){

    double valeur1(1.89), valeur2(-2.36474), valeur3(3.73736);

    double* choix(nullptr);

    switch (demander_nombre(1,3))
    {
    case 1 :
        choix = &valeur1;
        break;
    
    case 2:
        choix = &valeur2;
        break;

    case 3:
        choix = &valeur3;
        break;
    }


    cout << "vous avez choisi " << *choix << endl;



   
}





int main()
{

    selecteur();


    



   








    return 0;
}