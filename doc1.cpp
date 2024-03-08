#include <iostream>
#include <vector>

/
class Vertex;

class Edge
{
    friend class Vertex; 
protected:
    Vertex *target;
    float poids; 

public:
    Edge() {} 
    Edge(float i, Vertex *target) : target(target), poids(i)
    {
    }
};

class Vertex
{
    friend class Graph;

protected:
    bool marqueur;               
    std::vector<Edge> adjacents;
    int id;

public:
    // vr: manque le constructeur
    Vertex(int i) : marqueur(false), id(i) {}

    void add_edge(float value, Vertex *target)
    {
        adjacents.push_back(Edge(value, target));
    }
    void visit()
    {
        std::cout << "visite du sommet " << id << std::endl;
        marqueur = true;
        for (Edge &edge : adjacents)
        { // va à l'objet pointé cad le sommet adjacent
            std::cout << "      visite de l'edge " << id << " -> " << edge.target->id << std::endl;
            if (edge.target->marqueur == false)
            {
                edge.target->visit(); // parcours en profondeur
            };                        

    } 
};
};

class Graph
{
protected:
    std::vector<Vertex> vertices;

public:
    void add_vertex(int i)
    {
        vertices.push_back(Vertex(i));
    }
    void add_edge(int from, int to, float value)
    {
     
        vertices[from].add_edge(value, &vertices[to]);
    }

    void visit()
    {
        /
        for (Vertex &vertex : vertices)
        {
            vertex.marqueur = false;
        }
        
        for (Vertex &vertex : vertices)
        {
            vertex.visit();
        }
    }
};

int main()
{
    Graph g;
    g.add_vertex(0);
    g.add_vertex(1);
    g.add_vertex(2);
    g.add_edge(0, 1, 1.3);
    g.add_edge(0, 2, 2.5);
    g.add_edge(1, 2, 3.7);
    g.add_edge(2, 0, 4.2);
    g.add_edge(2, 1, 5.1);
    g.visit();
    
}; 
