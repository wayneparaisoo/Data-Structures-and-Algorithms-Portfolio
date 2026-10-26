#include <iostream>
#include <vector>


struct Edge {
    int from, to, weight;
};

class Graph {
    std::vector<int> vertices;   // vertex labels
    std::vector<Edge> edges;     // edge list

    bool hasVertex(int v) const {
        for (int x : vertices)
            if (x == v) return true;
        return false;
    }

public:
    // Add a vertex
    void addVertex(int v) {
        if (hasVertex(v)) {
            std::cerr << "Vertex " << v << " already exists\n";
            return;
        }
        vertices.push_back(v);
    }

    // Add an edge from u to v with a weight
    void addEdge(int u, int v, int weight = 1) {
        if (!hasVertex(u) || !hasVertex(v)) {
            std::cerr << "Vertex out of bounds: (" << u << ", " << v << ")\n";
            return;
        }
        edges.push_back({u, v, weight});
    }

    // Display the vertices
    void displayVertices() const {
        std::cout << "Vertices: ";
        for (int v : vertices) std::cout << v << " ";
        std::cout << "\n";
    }

    // Display the edges
    void displayEdges() const {
        std::cout << "Edges (from -> to : weight):\n";
        for (const Edge &e : edges)
            std::cout << "  " << e.from << " -> " << e.to << " : " << e.weight << "\n";
    }
};

int main() {
    Graph g;

    for (int i = 0; i < 6; i++) g.addVertex(i);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 4, 3);
    g.addEdge(2, 3, 2);
    g.addEdge(3, 1, 4);
    g.addEdge(4, 3, 3);

    g.displayVertices();
    std::cout << "\n";
    g.displayEdges();
    return 0;
}