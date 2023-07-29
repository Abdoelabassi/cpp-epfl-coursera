#include <iostream>


class Fleur{

    public:
        Fleur(const std::string& name, const std::string& color)
            : name(name), color(color)
            {
                std::cout << name << " fraichement cueillie" << std::endl;

            }
        Fleur(Fleur const& f)
            : name(f.name), color(f.color)
            {
                std::cout << "Fragile corolle taillée" << std::endl;
            }
        ~Fleur(){
            std::cout << "q'un simple souffle..." << std::endl;
        }
        void eclore() const{
            std::cout << "dans un cristal veine de " <<  color  <<std::endl;
        }



    private:
        std::string name;
        std::string color;




};

int main () { 
    Fleur f1("Violette", "bleu"); 
    Fleur f2(f1); 
    std::cout << "dans un cristal ";
    f2.eclore(); 
    std::cout << "Donne un poème un peu fleur bleue" << std::endl 
              << "ne laissant plus "; 
    
    
    
    return 0; 
     
     
    
}