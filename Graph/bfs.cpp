#include <iostream>
#include <queue>
#include "Graph.h"

using std::queue;

void bfs(Graph &graph) {
    const int n = graph.getSize();
    int** matrix = graph.getMatrix();
    int* mark = createArray(n);
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (mark[i] == 0) {
            q.push(i);
            while (!q.empty()) {
                int v = q.front();
                mark[v] = 1;
                printf("%d\n", v);
                for (int j = 0; j < n; ++j) {
                    if (mark[j] == 0) {
                        q.push(j);
                    }
                }
                q.pop();
            }
        }
    }
    freeArray(mark);
}

int main() {
    freopen("data.txt", "r", stdin);
    Graph g;
    g.showGraph();

    bfs(g);

    fclose(stdin);

    return 0;
}
