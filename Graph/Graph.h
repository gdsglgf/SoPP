#ifndef GRAPH_H
#define GRAPH_H

#include "func.h"

class Graph
{
    public:
        Graph();
        Graph(int n);
        ~Graph();
        void showGraph();
        int getSize();
        int** getMatrix();
    protected:
    private:
        int n;
        int** matrix;
};

#endif // GRAPH_H
