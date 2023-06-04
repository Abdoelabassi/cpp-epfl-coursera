#include <iostream>


using namespace std;

struct Complexe {

    double x;
    double y;

};

void affiche(Complexe const&z)
{
    cout << "Partie reelle: " << z.x << endl;
    cout << "Partie imaginaire: " << z.y << endl;
}

// Addition de deux nombres complexe
Complexe addition(Complexe &z1, Complexe &z2)
{
    Complexe p;

    p.x = z1.x + z2.x;
    p.y = z1.y + z2.y;

    return p;
}

// soustraction

Complexe soustraction(Complexe& z1, Complexe& z2)
{
    Complexe p;

    p.x = z1.x - z2.x;
    p.y = z1.y - z2.y;

    return p;
}

// multiplication de deux nombres complexe: z1*z2 = (x+iy)*(x'+iy') = x*x' + ix*y' +iy*x' - y*y', z=(x*x'- y*y',x*y' + y*x')

Complexe multiplication(Complexe &z1, Complexe &z2)
{
    Complexe p;

    p.x = z1.x*z2.x - z1.y*z2.y;
    p.y = z1.x*z2.y + z1.y*z2.x;

    return p;


}

// division de deux nombres complexe: z = ((x*x'+y*y')/(x'*x'+y'*y'), (y*x'-x*y')/(x'*x'+y'*y')).

Complexe division(Complexe& z1, Complexe&z2)
{
    Complexe p;

    p.x = (z1.x*z2.x + z1.y*z2.y) / (z1.x*z2.x + z1.y*z2.y);
    p.y = (z1.y*z2.x - z1.x*z2.y) / (z2.x*z2.x + z2.y*z2.y);

    return p;
}

int main()
{

    Complexe z1 {2.3, 4.5};
    Complexe z2 {3.5, 6.5};

    affiche(z1);
    affiche(z2);
    Complexe p(addition(z1,z2));
    cout << "(" << z1.x <<","  << z1.y << ") + " << "(" << z2.x << "," << z2.y << ") = " << "(" << p.x << "," << p.y << ")" <<endl;

    p = soustraction(z1, z2);
    cout << "(" << z1.x <<","  << z1.y << ") - " << "(" << z2.x << "," << z2.y << ") = " << "(" << p.x << "," << p.y << ")" <<endl;

    p = multiplication(z1, z2);
    cout << "(" << z1.x <<","  << z1.y << ") * " << "(" << z2.x << "," << z2.y << ") = " << "(" << p.x << "," << p.y << ")" <<endl;

    p = division(z1, z2);
    cout << "(" << z1.x <<","  << z1.y << ") / " << "(" << z2.x << "," << z2.y << ") = " << "(" << p.x << "," << p.y << ")" <<endl;







    return 0;
}