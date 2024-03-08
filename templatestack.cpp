
#include <iostream>
#include <stdexcept>


template <typename T> //peut etre utisé dans les hpp (pratique) 
class Stack
{
/*
template<class U>
friend std::ostream &operator<<(std::ostream &os, const Stack<U> &)
une fonction qui prend un argument une classe template doit etre template 
*/
friend std::ostream &operator<<(std::ostream &os, const Stack<T> &);
private:
    int nb;
    int size;
    T *tab;

public: 
    Stack(int m) : nb(0), size(m)
    {
       
        if (size <= 0)
        {
            throw std::invalid_argument("bad size of stack");
        }
        tab = new char[size];
    }

    ~Stack()
    {
        delete[] tab;
    }

    
    Stack(const Stack &rs) : nb(rs.nb), size(rs.size)
    {
        tab = new char[size];
        for (int i = 0; i < nb; i++)
        {
            tab[i] = rs.tab[i];
        }
    }

   
    void operator=(const Stack &rs) = delete;

    // EXERCICE 1: implémentez l'opérateur d'affectation pour mardi prochain

    // enfin les fonctions qui permettent de manipuler les piles empiler, dépiler etc.
    void push(char c)
    {
        if (isFull())
        {
            throw "stop";
        }
        tab[nb] = c;
        nb = nb + 1;
    }

    // je définis la méthode pop en dehors de la classe
    // voir plus bas
    char pop();

    // quand une méthode ne modifie pas l'objet sur lequel elle a été appelée
    // on la déclare comme const de manière à pouvoir l'appliquer sur les objets constants
    bool isEmpty() const
    {

        return nb == 0;
    }

    bool isFull() const
    {
        return nb == size;
    }

    void print() const
    {
        for (int i = 0; i < nb; i++)
        {
            std::cout << tab[i] << ' ';
        }
        std::cout << '\n';
    }

    char top()
    {
        if (isEmpty())
        {
            throw "stop";
        }
        return tab[nb - 1];
    }
};
// si je désire mettre l'implémentation d'une fonction membre
// en dehors de la définition de la structure de donnée Stack
// je fais de la manière suivante:
inline char Stack::pop()
{
    if (isEmpty())
    {
        throw "stop";
    }
    nb = nb - 1;
    return tab[nb];
}
// vous remarquez le inline on en parlera au prochain cours

// supposons que je n'ai pas de fonction top définie dans la structure de donnée
// je peux éventuellement en coder une de la manière suivante (merci à Gaspard)
/*
inline char Stack::top_stack(Stack &rs)
{
    char c = rs.pop();
    rs.push(c);
    return c;
}
*/
/*
int main()
{
    try
    {
        Stack s(-12);
    }
    catch (const char *e)
    {
        std:: cout<<e<<std::endl;
    }
}
*/

//un simple throw est une execption mais ne va pas arreter le code, try catch permet de dire que si expetion il y a, l'afficher et résoudre le probleme
//try catch est un mécanisme de rattrapage d'erreur 
//la librairie : <stdexcept>

int main()
{
    try
    {
        Stack<char> sc (5);
        sc.push('c');
        std::cout<<sc;
    }
    catch (const std::invalid_argument& e)
    {
        std:: cout<<e.what()<<std::endl;
    }
}
