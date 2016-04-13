#include <iostream>
#include <stack>
using std::stack;

void setZero(bool* mark, const int n) {
	for (int i = 0; i < n; ++i) {
		mark[i] = false;
	}
}

void dfs(int** graph, const int n) {
	bool mark[n];
	setZero(mark, n);

	stack<int> s;
	for (int i = 0; i < n; ++i) {
		if (mark[i] == 0) {
			s.push(i);
			while(!s.empty()) {
				int v = s.top();
				if (mark[v] == false) {
					printf("%d\n", v);
					mark[v] = true;
				}
				s.pop();
				for (int j = n - 1; j >= 0; --j) {
					// cannot using graph[v][j], because compiler does not how to address it
					// must using *((int*)graph + v * n + j)
					if (mark[j] == false && *((int*)graph + v * n + j) != 0) {
						s.push(j);
					}
				}
			}
		}
	}

	printf("size=%d\n", s.size());
}

int main() {
	const int n = 5;
	int graph[n][n] = {
		0, 1, 1, 0, 1,
		1, 0, 1, 0, 0,
		1, 1, 0, 0, 0,
		0, 0, 0, 0, 0,
		1, 0, 0, 0, 0
	};

	dfs((int**)graph, n);

	bool mark[n];
	for (int i = 0; i < n; ++i) {
		mark[i] = false;
	}

	stack<int> s;
	for (int i = 0; i < n; ++i) {
		if (mark[i] == 0) {
			s.push(i);
			while(!s.empty()) {
				int v = s.top();
				if (mark[v] == false) {
					printf("%d\n", v);
					mark[v] = true;
				}
				s.pop();
				for (int j = n - 1; j >= 0; --j) {
					if (mark[j] == false && graph[v][j] != 0) {
						s.push(j);
					}
				}
			}
		}
	}

	printf("size=%d\n", s.size());

	return 0;
}