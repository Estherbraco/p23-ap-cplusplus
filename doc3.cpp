class Shape
{
protected:
    int x;
    int y;
    int color;

public:
    Shape(int posx, int posy, int col = 230) : x(int posx), y(int posy), color(col) {}
    void move(int dx, int dy)
    {
        x = x + dx;
        y = y + dy;
    }
    virtual float area()=0; //évite d'attendre l'execution pour l'execution dynamique 
};
class Circle : public Shape
{
    int radius;

public:
    Cicrcle(int posx, int posy, int r, int col) : radius(r), Shape(posx, posy, col)
    {
        float area() { return 3.14 * radius * radius; }
    }
};
class Rectangle : public Shape
{
    int L;
    int l;
};
// le rectangle a deux type le type shape et le type rectangle : composé de 2 parties
// la methode area va etre specique à chaque classe alors que move à la class shape
int main()
{
    Circle c1(10, 20, 3)
        Circle c2(100, 200, 4)
        /*
        std::vector<Shape*> l;
        l.push_back(&c1);
        l.push_back(&c2);
        l[0].move(4,5);
        */
        c1.area();
    Shape *s = &c1; // s de type adresse de shape vaut la valeur pointée par c1
    s->move(4, 5);
    std::cout << s->area() << std::endl;
    return 0
}
