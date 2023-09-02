#include <iostream>
#include <vector>

using namespace std;

typedef size_t Degre;

class Polynome
{
    private:
        vector<double> p;


    public:
        Degre degre() const {return p.size() - 1;}
        Polynome::Polynome() : p(1,0.0){}
        Polynome::Polynome(double x) : p(1,x){}
        Polynome::Polynome(double coef, Degre deg): p(deg+1, 0.0)
        {
            p[deg] = coef;
        }

        friend ostream& operator<<(ostream&, Polynome const&);

        void affiche_coef(ostream&, Degre,bool) const;

};