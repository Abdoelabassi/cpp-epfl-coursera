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

        unsigned int lire_age() const {return age;}
        unsigned int lire_somme() const {return argent;}


};

class Assistance{

    public:
        void lire(const Papier& papier);
        void calculer();
        unsigned int announcer();


    private:
        unsigned int age_lu;
        unsigned int argent_lu;
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

void Assistance::lire(const Papier &p){
    cout << "[Assistance] " << " Je lire le papier " << endl;
    age_lu = p.lire_age();
    argent_lu = p.lire_somme();
}

void Assistance::calculer(){
    cout << "[Assistance]" << "Je cacule mentalement " << endl;
    resultat = age_lu*2;
    resultat += 5;
    resultat *= 50;
    resultat += argent_lu;
    resultat -= 365;
}

unsigned int Assistance::announcer(){
    cout << "[Assistance]" << "J'announce " << resultat << endl;
    return resultat;
}

void Spectateur::arriver(){
    cout << "[Spectateur]" << "J'entre en scene " << endl;
    cout << "Quel age ai-je?: ";
    cin >> age;
    do{
        cout << "Combien d'argents ai-je en poche (<100)?:  ";
        cin >> argent;
    }while(argent >= 100);
}

void Spectateur::ecrire(){
    cout << "[Spectateur]" << " J'ecris  le papier " << endl;
    papier_cigarette.ecrire(age, argent);
}

Papier Spectateur::montrez(){
    cout << "[Spectateur]" << " Je montre le papier" << endl;
    return papier_cigarette;
}

void Magician::tour_de_magie(Assistance &ass, Spectateur &sp){
    cout << "[Magician]" << " un petit tour de magie " << endl;
    sp.ecrire();
    ass.lire(sp.montrez());
    ass.calculer();
    calculer(ass.announcer());
    announcer();
}


void Magician::calculer(unsigned int resultat_recu){
    resultat_recu += 115;

    arge_devine = resultat_recu / 100;
    arge_devine = resultat_recu % 100;
}

void Magician::announcer(){
    cout << "[Magician]" << endl;

    cout << "Hmm ..." << "Je vois que vous etes " << arge_devine << " ans" << endl;
    cout << "Et que vous avez " << arge_devine << "franc en poche" << endl;
}