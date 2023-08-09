#include <iostream>

using namespace std;


int main()
{
	
		double x(0.0);
		
		cout << "Entrez une valeur pour x :\t";
		cin >> x;
		
		while (1){
			if ( x >= -1 and x < 1){
			
				cout << "x appartient a l'intervalle [-1,1[ " << endl;
				break;
			}else{
				cout << "X n'appertient pas a l'intervalle [-1,1[ " << endl;
				cout << "Entrez une nouvelle valeur :\t" ;
				cin >> x; 
			}
		}
	
	
	
	
	
	return 0;
	
	
}
