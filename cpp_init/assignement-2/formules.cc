#include <iostream>
#include <cmath>


using namespace std;


int main()
{
	
		double x(0.0);
		
		cout << "Entrez une valeur pour x :";
		cin >> x;
		
		double expression1 = x/(1-exp(x));
		double expression2 = (-x - sqrt(x*x - 8*x))/(2-x);
		double expression3 = x*log(x)*exp(2/(x-1));
		double expression4 = sqrt((sin(x) - x/20)*log(x*x - 1/x));
		
		if(x != 0){
			
			
			cout << "evaluation de l'expression 1 est : " << expression1 << endl;
			
		}else{
			
			cerr << "Expression " << expression1 << " est indéfinie" << endl;
		}
	    if( x > 1){
			
			cout << "expression3 = " << expression3 << endl;
			cout << "expression4 = " << expression4 << endl;
		}else{
			
			cerr << " Expressions " << "expression3 :" << expression3 << "expression4 :" << expression4 << "est indéfinie" << endl;
		}
		
		
		if (x > 2){
			
			cout << "evaluation de l'expression 2 :" << expression2 << endl;
			
			
			
		}else{
			
			cerr << "Expression 2 : " << expression2 << " est indéfinie" << endl;
		}
			
	
	
	
	return 0;
	
}
