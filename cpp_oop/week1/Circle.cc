#include <iostream>
#include <string>
#include <vector>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif 




using namespace std;

class Circle{

    private:
        double rayon;
        vector<double> centre{0.0,0.0};

    public:
        double getRayon() const {return rayon;}
        vector<double> getCentre() const {return centre;}

        void setRayon(double rayon){this->rayon = rayon;}
        void setCentre(double x, double y){this->centre[0] = x; this->centre[1] = y;}

        double surface() const {
            return M_PI*rayon*rayon;
        }


};

int main()
{
    Circle c;
    c.setRayon(4.5);
    c.setCentre(1.4,2.5);

    double rayon = c.getRayon();
    vector<double> centre = c.getCentre();
    double surface = c.surface();

    cout << "//////////////////////////" << endl;
    cout << "Rayon: " << rayon << endl;

    cout << "Coordonee de la circle: " << " (" << centre[0] << " , " << centre[1] << ")" << endl;
    cout << "Surface 2*pi*r= " << surface << endl;
    








    return 0;
}