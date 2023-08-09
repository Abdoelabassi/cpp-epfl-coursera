#include <iostream>
#include <vector>



using namespace std;


double scalaire(vector<double>& vec1, vector<double>& vec2)
{

    double ps(0);
    for(size_t i(0); i < vec1.size(); ++i ){

        ps += vec1[i]*vec2[i];



    }

    return ps;
}


int main()
{
    vector<double> vec1({1,2,3,4,5});

    vector<double> vec2({3,4,5,6,7});

    double produit_scalaire(scalaire(vec1, vec2));

    cout << "Le produit scalaire de vec1.vec2= " << produit_scalaire << endl;










    return 0;
}