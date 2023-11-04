#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Figure
{
    public:
        virtual void affiche() const = 0;
        virtual unique_ptr<Figure> copie() const = 0;
    virtual ~Figure(){cout << "Une figure de moin" << endl;}
};

class Cercle : public Figure
{
    private:
        unsigned int rayon;
    public:
        Cercle(unsigned int rayon_) : rayon(rayon_) {cout << "Constructeur Cercle cree" << endl;}
        Cercle(Cercle const& c): Figure(c), rayon(c.rayon)
        {
            cout << "copie d'un cercle de rayon " << rayon << endl;
        }

        ~Cercle(){cout << "Destructor called for Cercle" << endl;}

        void affiche() const
        {
            cout << "Rayon de Cercle: " << rayon << endl;
        }
        unique_ptr<Figure> copie() const override
        {
            return unique_ptr<Figure> (new Cercle(*this));
            
        }

};
class Carre: public Figure
{
    private:
        double cote;
    public:
        Carre() {cout << "Constructeur Caree cree" << endl;}
        Carre(double cote_): cote(cote_) {}
        Carre(Carre const& c): Figure(c), cote(c.cote)
        {
            cout << "Copie d'un Caree de cote " << cote << endl;
        }
        ~Carre() {cout << "Destructor called for Caree" << endl;}

        void affiche() const
        {
            cout << "Square's Cote: " << cote << endl;
        }
        unique_ptr<Figure> copie() const override
        {
            return unique_ptr<Figure> (new Carre(*this));
            
        }
};
class Triangle: public Figure
{
    private:
        double hauteur;
        double base;
    public:
        Triangle(){cout << "Constructeur triangle cree" << endl;}
        Triangle(double hauteur_, double base_): hauteur(hauteur_), base(base_){}
        Triangle(Triangle const& t): Figure(t), hauteur(t.hauteur), base(t.base) 
        {
            cout << "Copie d'un triangle d'hauteur " << hauteur << ", et de base " << base << endl;
        }
        ~Triangle(){cout << "Destructor called for Triangle" << endl;}

        void affiche() const 
        {
            cout << "Hauteur de triangle: " << hauteur << ", base de triangle: " << base << endl;
        }
        unique_ptr<Figure> copie() const override
        {
            return unique_ptr<Figure> (new Triangle(*this));
            
        }
};

class Dessin
{
    public:
        ~Dessin()
        {
            cout << "Le dessin s'efface..." << endl;
        }
        void ajouteFigure(Figure const& figure){
            figures.push_back(figure.copie());
        }
        void affiche() const
        {
            cout << "Je contient " << endl;
            for (size_t i(0); i < figures.size(); i++)
            {
                figures[i]->affiche();
            }
        }
    private:
        vector<unique_ptr<Figure>> figures;
};

void unCercleDePlus(Dessin const& img) {
   Dessin tmp(img);            
   tmp.ajouteFigure(Cercle(1));
   cout << "Affichage de 'tmp': " << endl;
   tmp.affiche();          
}

int main() {
   Dessin dessin;         
   dessin.ajouteFigure(Triangle(3,4));               
   dessin.ajouteFigure(Carre(2));
   dessin.ajouteFigure(Triangle(6,1));
   dessin.ajouteFigure(Cercle(12));
   cout << endl << "Affichage du dessin : " << endl;
   dessin.affiche();

   unCercleDePlus(dessin);
}