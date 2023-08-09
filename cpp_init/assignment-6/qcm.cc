#include <iostream>
#include <vector>
#include <string>


using namespace std;

struct QCM 
{
    string question;
    vector<string> reponses;
    int solution;

};

void affiche(QCM const &q)
{
    cout << q.question << endl;

    for (size_t i(0); i < q.reponses.size(); ++i)
    {
        cout << "- " << (i+1) << " " << q.reponses[i] << endl;
    }
}

int demander_nombre()
{
    int n(0);

    do{
        cout << "entrez un nombre entre 1 et 5 (votre reponse): ";
        cin >> n;
    }while(!(n >= 1 and n <= 5));

    return n;
}



vector<QCM> cree_examen()
{
    
QCM p1{ "Combien de dents possède un éléphant adulte",
{ "32", "de 6 à 10", "beaucoup", "24", "2" },
2 
};
QCM p2{"Laquelle des instructions suivantes est un prototype de fonction",
{ "int f(0);" ,
"int f(int 0);" ,
"int f(int i);" ,
"int f(i);" },
3};
QCM p3{"Qui pose des questions stupides",
{ "le prof. de math",
"mon copain/ma copine",
"le prof. de physique",
"moi",
"le prof. d'info",
"personne, il n'y a pas de question stupide",
"les sondages" } ,
6};
   vector<QCM> Examen{p1,p2,p3};
   return Examen;
   

}

vector<int> poser_question(vector<QCM> &p)
{
    vector<int> reponses;

    for (auto qcm: p)
    {
        affiche(qcm);
        int n = demander_nombre();
        reponses.push_back(n);
        
    }

    return reponses;

}

void comparer_reponse(vector<QCM> &p)
{
    int score(0);
    vector<int> reponses = poser_question(p);
    for(size_t i(0); i < reponses.size(); ++i )
    {
        if(reponses[i] == p[i].solution )
        {
            score++;
        }
    }
    cout << "Vous avez trouvez " << score << " bonne reponses sur " << p.size() << endl;
}


int main()
{

    vector<QCM> Examen (cree_examen());

    comparer_reponse(Examen);






    return 0;
}