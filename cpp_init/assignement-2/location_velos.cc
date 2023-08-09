#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  cout << "Donnez l'heure de début de la location (un entier) : ";
  int debut;
  cin >> debut;

  cout << "Donnez l'heure de fin de la location (un entier) : ";
  int fin;
  cin >> fin;

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/

   

	
    
	  cout << "Vous avez loué votre vélo pendant" << endl;
	  
	    if ((debut >= 0 and fin <= 24) and (debut < fin)){
        if(debut >= 0 and debut <= 7){

			cout << (min(fin,7) - debut) <<" heure(s) au tarif horaire de " << " 1 franc(s)" << endl;
			 
	   }

     if(debut < 17 and fin >= 7){
		   
		   cout << min(fin, 17) - max(debut, 7) <<" heure(s) au tarif horaire de " << " 2 franc(s)" << endl;
			 
		  
	   
	   
	    }
      
      if(fin > 17 and fin <= 24){

       cout << fin - max(debut, 17) <<" heure(s) au tarif horaire de " << " 1 franc(s)" << endl;
			 
		
    }
    
    }else{

       cout << "Les heures doivent être comprises entre 0 et 24 !" << endl;
       cout << "Bizarre, vous n'avez pas loué votre vélo bien longtemps !" << endl;
       cout << "Bizarre, le début de la location est après la fin ..." << endl;

    }
     cout << "Le montant total à payer est de " << 2*(min(fin, 17) - max(debut, 7)) + fin - max(debut, 17) << " franc(s)." << endl;
      
  /*******************************************
   * Ne rien modifier après cette ligne.
   *******************************************/

  return 0;
}
