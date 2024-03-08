#include <iostream>
#include "shape.hpp"
class Rectangle : public Shape
{
    int longeur ;
    int largeur ;

public:
    Rectangle(int posx, int posy, int l, int L, int col) : longeur(l), largeur(L), Shape(posx, posy, col)
    {
    }
 float area() const { return longeur*largeur ; }
};
