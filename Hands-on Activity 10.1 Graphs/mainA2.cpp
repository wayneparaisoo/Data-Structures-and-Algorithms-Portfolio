#include <iostream>
#include <vector>
#include <iomanip>

// Graph using an adjacency matrix
class MatrixGraph {
    int V;                                  // number of vertices
    std::vector<std::vector<int>> matrix;   // 0 means no edge

public:
    MatrixGraph() : V(0) {}

    // add a vertex
    void addVertex() {
        for (auto &row : matrix) row.push_back(0);   // new column
        matrix.push_back(std::vector<int>(V + 1, 0)); // new row
        V++;
    }

    // add an edge from u to v
    void addEdge(int u, int v, int weight = 1) {
        if (u < 0 || u >= V || v < 0 || v >= V) {
            std::cerr << "Vertex out of bounds: (" << u << ", " << v << ")\n";
            return;
        }
        matrix[u][v] = weight;
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
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (matrix[i][j] != 0)   // skip empty spots
                    std::cout << "  " << i << " -> " << j << " : " << matrix[i][j] << "\n";
    }

    // show the matrix
    void displayMatrix() const {
        std::cout << "Adjacency matrix:\n    ";
        for (int j = 0; j < V; j++) std::cout << std::setw(3) << j;
        std::cout << "\n";
        for (int i = 0; i < V; i++) {
            std::cout << std::setw(3) << i << " ";
            for (int j = 0; j < V; j++) std::cout << std::setw(3) << matrix[i][j];
            std::cout << "\n";
        }
    }
};

int main() {
    MatrixGraph g;

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
    g.displayMatrix();
    return 0;
}