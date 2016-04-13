#ifndef FUNC_H
#define FUNC_H

#include <memory.h>

int* createArray(int n) {
    int* array = NULL;
    if (n > 0) {
        array = new int[n];
        memset(array, 0, sizeof(int) * n);
    }

    return array;    
}

void freeArray(int* array) {
    delete [] array;
}

int** createSpace(int n) {
    int** data = NULL;
    if (n > 0) {
        data = new int*[n];
        for (int i = 0; i < n; ++i) {
            data[i] = new int[n];
            memset(data[i], 0, sizeof(int) * n);
        }
    }
    return data;
}

void freeSpace(int** data, int n) {
    for (int i = 0; i < n; ++i) {
        delete [] data[i];
    }
    delete [] data;
}

void loadMatrix(int** data, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            int v;
            std::cin >> v;
            data[i][j] = v;
            data[j][i] = v; 
        }
    }
}

void showMatrix(int** data, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

#endif // FUNC_H