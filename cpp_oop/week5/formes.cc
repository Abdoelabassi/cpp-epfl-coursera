#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

class Forme
{
    public:
    virtual void description() const{
        cout << "Ceci une forme!" << endl;
    }

};

class Cercle: public Forme
{
    public:
    void description() const{
        cout << "Ceci une circle!" << endl;
    }

};

void affichaeDesc(Forme &f)
{
    f.description();
}


int main() {
 Forme f;
 Cercle c;
 affichaeDesc(f);
 affichaeDesc(c);
 return 0;
}