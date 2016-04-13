#include "func.h"

typedef struct {
    int n;
    int** data;
} Graph;

void createSpace(Graph &g) {
    g.data = createSpace(g.n);
}

void freeSpace(Graph g) {
    freeSpace(g.data, g.n);
}

Graph loadGraph() {
    Graph g;
    std::cin >> g.n;

    g.data = createSpace(g.n);
    loadMatrix(g.data, g.n);

    return g;
}

void showGraph(Graph g) {
    showMatrix(g.data, g.n);
}