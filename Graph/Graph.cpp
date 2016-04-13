#include <iostream>
#include "Graph.h"

Graph::Graph() {
    std::cin >> this->n;
    this->matrix = createSpace(this->n);
    loadMatrix(this->matrix, this->n);
}

Graph::Graph(int n) {
    this->n = n;
    this->matrix = createSpace(n);
    loadMatrix(this->matrix, this->n);
    std::cout << "Graph Constructor" << std::endl;
}

Graph::~Graph() {
    freeSpace(this->matrix, this->n);
    std::cout << "Graph Deconstructor" << std::endl;
}

void Graph::showGraph() {
    showMatrix(this->matrix, this->n);
}

int Graph::getSize() {
    return this->n;
}


int** Graph::getMatrix() {
    return this->matrix;
}
