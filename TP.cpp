#include <iostream>
#include <vector>

class Vertex;

 class Edge
{
protected:
    Vertex *target;
    int poids;
    public:
    Edge(int i, Vertex *target) : target(target), poids(i) {
    }
};



class Vertex
{
protected:
    int marqueur == 0
    std::vector<Edge> adjacents;
    int id;
public:
    void add_edge (Edge e) {
        adjacents.push_back(e);
    }
};


class Graph
{
protected:
    std::vector<Vertex> vertices;
    public:
    
    void add_vertex(Vertex ver) {
        vertices.push_back(ver);
    }

};

int main () {
Graph g;
Marquer(s){
    if (int marqueur == 0){
        marqueur=1
    };
};
visit(int s,Graph graph){
    Marquer(s);
    for (Vertex *target : std::vector<Edge> adjacents ){ //va à l'objet pointé cad le sommet adjacent 
        if ( marqueur ==0){
            visit(*target,Graph graph) //parcour en profondeur 
        };
    };

};
};
