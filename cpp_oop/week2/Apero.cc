#include <iostream>


class Apero {

    public:

        Apero(){
            std::cout << "l'heure de l'apero est sonnee" << std::endl;
        } 
        ~Apero()
        {
            std::cout << "A table" << std::endl;
        }
        void bis(){
            std::cout << "Encore une?" << std::endl;
        }

};

int main(){

    Apero bic;
    std::cout << "Super! " << std::endl;
    bic.bis();
    std::cout << "Non, merci!" << std::endl;






    return 0;
}