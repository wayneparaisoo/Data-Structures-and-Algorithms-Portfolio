#include <iostream>
#include <vector>

// Graph using an adjacency list
class ListGraph {
    struct Neighbor { int to, weight; };

    int V;                                      // number of vertices
    std::vector<std::vector<Neighbor>> list;    // neighbors of each vertex

public:
    ListGraph() : V(0) {}

    // add a vertex
    void addVertex() {
        list.push_back({});   // empty list for the new vertex
        V++;
    }

    // add an edge from u to v
    void addEdge(int u, int v, int weight = 1) {
        if (u < 0 || u >= V || v < 0 || v >= V) {
            std::cerr << "Vertex out of bounds: (" << u << ", " << v << ")\n";
            return;
        }
        list[u].push_back({v, weight});
    }

    // show the vertices
    void displayVertices() const {
        std::cout << "Vertices: ";
        for (int i = 0; i < V; i++) std::cout << i << " ";
        std::cout << "\n";
    }

    // show the edges
    void displayEdges() const {
        std::cout << "Edges (from -> to : weight):\n";
        for (int u = 0; u < V; u++)
            for (const auto &n : list[u])
                std::cout << "  " << u << " -> " << n.to << " : " << n.weight << "\n";
    }

    // show the adjacency list
    void displayList() const {
        std::cout << "Adjacency list (vertex -> neighbor(weight)):\n";
        for (int i = 0; i < V; i++) {
            std::cout << "  " << i << " ->";
            if (list[i].empty()) std::cout << " (none)";   // no edges
            for (const auto &n : list[i])
                std::cout << " " << n.to << "(" << n.weight << ")";
            std::cout << "\n";
        }
    }
};

int main() {
    ListGraph g;

    // add 6 vertices (0 to 5)
    for (int i = 0; i < 6; i++) g.addVertex();

    // add edges (from, to, weight)
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 4, 3);
    g.addEdge(2, 3, 2);
    g.addEdge(3, 1, 4);
    g.addEdge(4, 3, 3);

    g.displayVertices();
    std::cout << "\n";
    g.displayEdges();
    std::cout << "\n";
    g.displayList();
    return 0;
}