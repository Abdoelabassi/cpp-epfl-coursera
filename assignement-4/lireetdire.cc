#include <iostream>
using namespace std;

int separer_chiffre_gauche(int& nombre)
{
  int dix(1);
  int temp(nombre);
  while (temp >= 10) {
    dix  *= 10;
    temp /= 10;
  }
  nombre %= dix;
  return temp;
}

/*****************************************************
 * ComplÃ©ter le code Ã  partir d'ici
 *****************************************************/

void ajouter_chiffre_droit(int& nombre, int chiffre)
{
    nombre = (nombre*10) + chiffre;
}

void dire_chiffre(int& nombre, int repetitions_chiffre, int chiffre)
{
    for(int i=0;i<2;++i){
        ajouter_chiffre_droit(nombre, repetitions_chiffre);
        repetitions_chiffre = chiffre;

    }
}

int lire_et_dire(int nombre)
{
}

/*******************************************
 * Ne rien modifier aprÃ¨s cette ligne.
 *******************************************/

void repeter_lire_et_dire(int& nombre, int fois)
{
  while (fois-- > 0) {
    nombre = lire_et_dire(nombre);
  }
}

int main()
{
  int nombre(1);
  int fois(1);
  cin >> nombre >> fois;
  repeter_lire_et_dire(nombre, fois);
  cout << nombre << endl;
  return 0;
}