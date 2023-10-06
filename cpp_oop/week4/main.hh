#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int distance(int x, int y)
{
    return abs(x - y);
}



class Creature
{
    protected:
    const string nom_;
    int niveau_;
    int points_de_vie_;
    int force_;
    int position_;

    public:
        Creature(const string nom, int niveau, int points_de_vie, int force, int position);

        bool vivant() const;
        int points_attaque() const;
        void deplacer(int x);
        void audieux() const;
        int position() const;
        void faiblir(int x);
        void afficher() const;
};

class Dragon : public Creature
{
    private:
        int portee_flammee_;
    public:
        Dragon(const string nom, int niveau, int points_de_vie, int force, int portee_flamme, int position);
        
        void voler(int pos);

        void souffle_sur(Creature& bete);

};

class Hydre : public Creature
{
    private:
        int longueur_cou_;
        int dose_poison_;

    public:
        Hydre(const string nom, int niveau, int points_de_vie , int force, int longueur_cou, int dose_posion, int position);

        void empoisonne(Creature& bete);

};

#endif