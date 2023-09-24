#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class EnsembleFini
{
    protected:
        unsigned int p;

    public:
        EnsembleFini(unsigned int p_) : p(p_){} 

};

class Groupe : public EnsembleFini
{
    public:
        Groupe(unsigned int p_) : EnsembleFini(p_) {}
        unsigned int add(unsigned int a, unsigned int b)
        {
            return (a + b) % p;
        }

};

class Anneau : public Groupe
{
    public:
        Anneau(unsigned int p_) : Groupe(p_) {}
        unsigned int mult(unsigned int a, unsigned int b)
        {
            return (a * b) % p;
        }

};

class Corps : public Anneau
{
    public:
        Corps(unsigned int p_) : Anneau(p) {}

        unsigned int inv(unsigned int x)
        {
            if (x != 0)
            {
                int prev_u(1), y(p), u(0), new_u, q, r;

                while ( y != 0)
                {
                    q = x / y;
                    r = x % y;
                    x = y;
                    y = r;
                    new_u = prev_u - q * u;
                    prev_u = u;
                    u = new_u;
                }
                
                return (u + p) % p;

            }
            else
            {
                return 0;
            }

        }

        unsigned int div(unsigned int x)
        {
            return mult(x, inv(x));
        }

};

int main()
{
    Corps k(5); // le corps Z/5Z

  cout << "0 + 1 = " << k.add(0, 1)  << endl;
  cout << "3 + 3 = " << k.add(3, 3)  << endl;
  cout << "3 * 2 = " << k.mult(3, 2) << endl;
  cout << "1/2 = "   << k.inv(2)     << endl;
  cout << "3 * 4 = " << k.mult(3, 4) << endl;





    return 0;
}