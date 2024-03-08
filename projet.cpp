#include <iostream>

class Element
{
public:
    int x;
    int y; // on suppose que le jeu est en 2D
public:
    Element(int posx, int posy, int posz) : x(posx), y(posy), z(posz) {}

public:
    void move(int dx, int dy, int dz)
    {
        x = x + dx;
        y = y + dy;
    };
} class Personnage : public Element
{
public:
    int sante;
    int force;
    int niveau_experience;
    int vie; // vu qu'il peut y avoir des morts pour chaque combat, j'ai ajouté un système de vie pour pas que le jeu soit trop court

public:
    Personnage(int posx, int posy, int posz, int s, int f, int n, int v) : x(posx), y(posy), z(posz), sante(s), force(f), niveau_experience(n), vie(v)
    {
    }
    void deroulement(Personnage Perso)
    {
        if (Perso.niveau_experience >= 10)
        {
            Perso.niveau_experience = Perso.niveau_experience - 10;
            Perso.sante = Perso.sante + 1;
            Perso.force = Perso.force + 1; // j'aimerais que le perso ait le choix entre augmenter sa force et sa santé pour qu'il ait des stratégies différentes dans les combats mais je ne sais pas comment faire
        };
    }
    void combat(Personnage Perso1, Personnage Perso2) bool defense(Personnage Perso2) {} // comment expremier le choix ? si l' adversaire y a choisi ceci alors blablabla
    void attaque(Perso1, Perso2)
    { // le Perso1 attaque le Perso 2; trois possibilités pour chaque perso : attaquer (attaque est lancée), ne rien faire (défense vaut 0), se défendre (défense vaut 1)
        if (Perso1.force > Perso2.sante)
            and(defense(Perso2) == False)
            {
                if (Perso2.vie != 0)
                {
                    Perso2.vie = Perso2.vie - 1;
                    Perso1.niveau_experience = Perso1.niveau_experience + 3;
                    Perso2.niveau_experience = Perso2.niveau_experience + 1;
                };
            };
        if (Perso1.force > Perso2.sante)
            and(defense(Perso2) == True)
            {
                {
                    Perso1.niveau_experience = Perso1.niveau_experience + 2;
                    Perso2.niveau_experience = Perso2.niveau_experience + 2;
                };
            };
        if (Perso1.force < Perso2.sante)
        {
            if (Perso1.vie != 0)
            {
                Perso1.vie = Perso1.vie - 1;
                Perso1.niveau_experience = Perso1.niveau_experience + 1;
                Perso2.niveau_experience = Perso2.niveau_experience + 3;
            };
        };
    }
} class Guerrier : public Personnage
{
public:
    Guerrier(int s = 2, int f = 4, int n) : Personnage(s, f, n) {} // un guerrier aime le combat donc grande force
} class Maitre : public Personnage
{
public:
    Maitre(int s = 5, int f = 2, int n) : Personnage(s, f, n) {} // un Maitre est compliqué à attaquer donc grande santé
} 
class Objet : class Element {}
class Game
{ public :
    void play(Personnage Perso)
    {
        std::cout << "votre action : ";
        char c;
        std::cin >> c;
        if (c == 'q'){Perso.posx =Perso.posx-1;};
        if (c == 'd'){Perso.posx =Perso.posx+1;};
        if (c == 'z'){Perso.posy =Perso.posy+1;};
        if (c == 's'){Perso.posy =Perso.posy-1;};

        }
    }

int main(Personnage Perso)
{
    if (Perso.vie == 0)
    {
        std::cout << "GAME OVER" << std::endl
    };
}