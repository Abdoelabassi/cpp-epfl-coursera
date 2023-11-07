#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;


class Animal
{
    public:
        Animal() {cout << "Animal class saying Hi to its children!." << endl;}
        virtual ~Animal(){cout << "You called Animal destructor " << endl;}

};

class Vivipare: public virtual Animal
{
    
    public:
        Vivipare(unsigned int duree_gestion_ = 128) : duree_gestion(duree_gestion_)
        {
            cout << "Vivipare called for duty!." << endl;
        }
    void naissance() const
    {
        cout << "Après " << duree_gestion << " jours de duree_gestion, je viens de mettre au monde un nouveau bébé." << endl;
    }
    ~Vivipare() {cout << "You called Vivipare destructor " << endl;}

    protected:
        unsigned int duree_gestion;


};

class Ovipare: public virtual Animal
{
    protected:
        unsigned int n_ouef;
    public:
        Ovipare(unsigned int ouef = 2): n_ouef(ouef)
        {
            cout << "Ovipare called for duty!" << endl;
        }
        ~Ovipare() {cout << "You called Ovipare destrcutor " << endl;}
    void naissance() const
    {
        cout << "Je viens de pondre environ " << n_ouef << " oeuf(s)." << endl;
    }


};



class Ovovivipare: public Vivipare, public Ovipare
{
    public:
        Ovovivipare(unsigned int jours, unsigned int n_oeuf , bool rare_ = false)
            : Vivipare(jours), Ovipare(n_oeuf) ,rare(rare_) 
            {
                cout << "Ovovivipare called for duty!." << endl;
            }

        ~Ovovivipare(){cout << "You called Ovovivipare destrictor " << endl;}
        void naissance() const
        {
            cout << "Après " << duree_gestion << " jours de gestation, je viens de mettre au monde " << n_ouef << " nouveau(x) bébé(s)." << endl;
        }
        

    protected:
        bool rare;

};

int main()
{
    Ovovivipare o(200, 6);
    o.naissance();





    return 0;

}