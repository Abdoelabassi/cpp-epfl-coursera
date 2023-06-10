#include <iostream>
#include <string>

using namespace std;

char decale(char c, char debut, int decalage);
char code(char c, int d);
string code(string chaine, int d);
string decode(string chaine, int decalage);

// function decalage
char decale(char c, char debut, int decalage)
{
    while(decalage < 0)
    {
        decalage += 26;
    }

    return debut + (((c-debut) + decalage) % 26  );

}

char code(char c, int d)
{
    char debut;
    if(c >= 'a' and c <= 'z' )
    {
        debut = 'a';
        return decale(c,debut,d);
    }
    else if(c >= 'A' and c <= 'Z' )
    {
        debut = 'A';
        return decale(c,debut,d);
    }

    return c;
}

string code(string chaine, int d)
{
    string coder;

    for (auto c : chaine)
    {
        coder += code(c,d);
        
        
    }


    return coder;
}

string decode(string chaine, int decalage)
{
    string decoder = code(chaine,  -decalage);

    return decoder;
}

int main()
{

    





    return 0;
}