#include <iostream>
#include <cmath>


using namespace std;

int main()
{
	
	double a(0.0);
	double b(0.0);
	double c(0.0);
	
	cout << "Enterez une value non null pour a = :\t";
	cin >> a;
	if (a == 0.0){
		cerr << "a is null :-( " << endl;
		return 1;
	}
	
	cout << "Entrez une valeur pour b :\t ";
	cin >> b;
	cout << "Entrez une valeur pour c :\t ";
	cin >> c;
	
	double delta(b*b - 4*a*c);
	
	if (delta < 0.0){
		
		cout << "Aucun solutions réelles \n" << endl;
	}else if(delta > 0.0){
		
		cout << "Deux solution : " << " x1 = (-b - sqrt(delta))/2a :" << (-b -sqrt(delta))/2*a << 
		" et x2 =  (-b+sqrt(delta))/2a : " << (-b + sqrt(delta))/2*a << endl;
	}else{
		 cout << "Une solution unique : " << " x0 = " << -b/2*a << endl;
	}
	
	
	
	
	
	return 0;
	
	
	
	
}
