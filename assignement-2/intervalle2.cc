#include <iostream>


using namespace std;


int main()
{
	
		double a(0.0);
		
		while (1){
			
			cout << "Entrez une valeur pour a :\t";
			
			cin >> a;
			
			if ((a >= 2 and a < 3) or ( a > 0 and a <= 1) or ( a >= -10 and a <= -2)){
				
				cout << " a appartient a l'intervalle [2,3[ U ]0,1] u [-10,-2]" << endl;
				break;
			}else{
				cout << " a n'appartient pas a l'intervalle [2,3[ U ]0,1] u [-10,-2]" << endl;
			}
		}

	
	
	
	
	
	return 0;
	
}
