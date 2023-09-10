#include <iostream>
#include <vector>

using namespace std;

typedef size_t Degre;

class Polynome
{
    private:
        vector<double> p;


    public:
        // constructors
        Polynome();
        Polynome(double x);
        Polynome(double coef, Degre deg);
        // destructor
        ~Polynome();

        // methods
        Degre degre() const;
        void affiche_coef(ostream&, Degre, bool) const;


        // intern operators
        Polynome& operator*=(Polynome const& p);
        Polynome& operator*=(double);



        


        
        // friends: grant access to the private attributes
        friend ostream& operator<<(ostream&, Polynome const&);
        friend const Polynome operator*(Polynome p, Polynome const& q);



};
// constructors
Polynome::Polynome() : p(1, 0.0)
{}

Polynome::Polynome(double x) : p(1, x)
{}

Polynome::Polynome(double coef, Degre deg) : p(deg + 1, 0.0)
{
    p[deg] = coef;
}
// destructor
Polynome::~Polynome()
{}

// methods
Degre Polynome::degre() const
{
    return p.size() - 1;

}

void Polynome::affiche_coef(ostream& out, Degre puissance, bool signe = true) const 
{ 
    double const c(p[puissance]); 
    if (c != 0)
    { 
        if (signe and (c > 0.0)) 
            out << "+"; 
            out << c; 
        if (puissance > 1) 
            out << "*X^" << puissance; 
        else if (puissance == 1) 
            out << "*X"; 
    }
    else if (degre() == 0) 
    { 
        // degré 0 : afficher quand meme le 0 si rien d'autre 
        out << 0; 
    } 
}

 // ----------------------------Operators------------------------------------ 
 ostream& operator<<(ostream& sortie, const Polynome& polynome) { 
    // plus haut degré : pas de signe + devant 
    Degre i(polynome.degre()); 
    polynome.affiche_coef(sortie, i, false);
    // degré de N à 0 : +a*X^i 
    if (i > 0) 
    { 
        for (i--; i > 0; i--) 
        {
            polynome.affiche_coef(sortie, i); 
        }

        polynome.affiche_coef(sortie, 0); 

    }
 
 return sortie; 
 }

  const Polynome operator*(Polynome p, Polynome const& q)
    {
        const Degre dp(p.degre());
        const Degre dq(q.degre());

        Polynome r(0.0, dp + dq);

        for (Degre i(0); i < dp; i++)
        {
            for (Degre j(0); j < dq; j++)
            {
                r.p[i+j] += p.p[i]*q.p[j];
            }
        }

        return r;
    }

Polynome& Polynome::operator*=(Polynome const& p)
{
    return *this = *this * p;
}

Polynome& Polynome::operator*=(double a)
{
    for (Degre i(0); i < degre(); i++)
    {
        p[i] *= a;
    }

    return *this;

}

const Polynome operator*(Polynome p, double a)
{
    return p *= a;
}

const Polynome operator*(double x, Polynome p)
{
    return Polynome(p) *= x;
}

 int main()
 {
    Polynome p(3.5, 5);

    Polynome q(4.6, 3), r;

    r = p * q;
    cout << p << " * " << q << " = " << r << endl;

    r *= 2.0;

    cout << "* 2 = " << r << endl;

    return (0);
 }
 
