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


void Polynome::affiche_coef(ostream& out, Degre puissance, bool signe) const 
{ double const c(p[puissance]); 
if (c != 0)
{ 
    if (signe and (c > 0.0)) out << "+"; 
out << c; 
if (puissance > 1) 
out << "*X^" << puissance; 
else if (puissance == 1) 
out << "*X"; 
}else if (degre() == 0) 
{ // degré 0 : afficher quand meme le 0 si rien d'autre 
out << 0; 
} 
}
 // ---------------------------------------------------------------------- 
 ostream& operator<<(ostream& sortie, const Polynome& polynome) { 
    // plus haut degré : pas de signe + devant 
    Degre i(polynome.degre()); 
    polynome.affiche_coef(sortie, i, false);
    // degré de N à 0 : +a*X^i 
    if (i > 0) 
    { 
        for (i--; i > 0; i--) polynome.affiche_coef(sortie, i, true); 
        polynome.affiche_coef(sortie, 0, false); 
    }
 
 return sortie; 
 }
 
