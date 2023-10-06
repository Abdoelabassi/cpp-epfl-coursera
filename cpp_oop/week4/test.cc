#include "main.hh"

Creature::Creature(const string nom, int niveau, int points_de_vie, int force, int position = 0)
{}

bool Creature::vivant() const
{
     if (points_de_vie_ > 0)
      {
        return true;
      }
      else return false;
}

int Creature::points_attaque() const
{
    if (vivant() == true)
      {
        return niveau_ * force_;
      }

      else return 0;
}
void Creature::deplacer(int x)
{
    position_ += x;
}

void Creature::audieux() const
{
    cout << nom_ << " n'est plus! " << endl;
}

int Creature::position() const
{
    return position_;
}

void Creature::faiblir(int x)
{
    if (vivant() == true)
      {
        points_de_vie_ -= x;
        if (points_de_vie_ < 0)
        {
          points_de_vie_ = 0;
        }

      }
      if (vivant() == false)
      {
        points_de_vie_ = 0;
        audieux();
      }
}

void Creature::afficher() const
{
    cout << nom_ << ", niveau: " << niveau_ << ", points de vie: " << points_de_vie_ << ", force: " << force_ << ", points d'attaque: " << points_attaque() << ", position: " << position_ << endl;
}

Dragon::Dragon(const string nom, int niveau, int points_de_vie, int force, int portee_flamme, int position = 0)
    : Creature(nom, niveau, points_de_vie, force, position), portee_flammee_(portee_flamme)
{}

void Dragon::voler(int x)
{
    deplacer(x);
}

void Dragon::souffle_sur(Creature& bete)
{
    int d(distance(bete.position(), this->position()));
      if (this->vivant() == true && bete.vivant() == true)
      {
        if (portee_flammee_ >= d)
        {
          bete.faiblir(this->points_attaque());
          this->faiblir(d);
        }
        if (bete.vivant() == false && this->vivant() == true)
        {
          this->niveau_++;
        }
      }
}

Hydre::Hydre(const string nom, int niveau, int points_de_vie , int force, int longueur_cou, int dose_posion, int position = 0)
    : Creature(nom, niveau, points_de_vie, force, position), longueur_cou_(longueur_cou), dose_poison_(dose_posion)
{}

void Hydre::empoisonne(Creature& bete)
{
    int d = distance(bete.position(), this->position());
        if (this->vivant() == true && bete.vivant() == true)
        {
         if (longueur_cou_ >= d)
         {
            bete.faiblir(this->points_attaque() + this->dose_poison_);
         }
         if (bete.vivant() == false && this->vivant() == true)
         {
          this->niveau_++;
         }
        }
}

int main()
{






    return 0;
}


