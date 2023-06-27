#include <iostream>
#include <string>

using namespace std;

class Papier{

    private:
        unsigned int age;
        unsigned int argent;

    public:
        void ecrire(unsigned int age, unsigned int argent){
            this->age = age;
            this->argent = argent;
        }

        unsigned int lire_age(){return age;}
        unsigned int lire_somme(){return argent;}


};

class Assistance{

    public:
        void lire(const Papier& papier);
        void calculer();
        unsigned int announcer();


    private:
        unsigned int age;
        unsigned int argent;
        unsigned int resultat;

};


class Spectateur{

    public:
    
        void arriver(); // lorsqu'il entre dans la salle
        void ecrire(); // ecrire sur la papier

        Papier montrez(); // montrer le papier


    private:
        unsigned int age;
        unsigned int argent;

        Papier papier_cigarette;

};


class Magician{

    public:

        void tour_de_magie(Assistance &ass, Spectateur &sp);



    private:
        void calculer(unsigned int resultat);
        void announcer();

        unsigned int arge_devine;
        unsigned int argent_devine;

};









int main(){

    Spectateur jk_rowling;
    jk_rowling.arriver();

    Magician Dambeldor;
    Assistance Harry;
    

   
  



    return 0;
}