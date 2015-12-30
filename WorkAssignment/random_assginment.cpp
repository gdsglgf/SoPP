#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int random(int n) {
    srand(time(0));
    return rand() % n;
}

int* originData(int size) {
    int* data = NULL;
    if (size > 0) {
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = i;
        }
    }
    return data;
}

void swap(int* data, int i, int j) {
    int temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

int* randomData(int size) {
    int* data = originData(size);
    if (data != NULL) {
        for (int i = size - 1; i > 0; --i) {
            int index = random(i);
            swap(data, index, i);
        }
    }    
    return data;
}

void showData(int* data, int n) {
    for (int i = 0; i < n; ++i) {
        cout << i << "->" << data[i] << endl;
    }
}

int main() {
    int size = 10;    
    cout << "Random Assignment Method:\n";
    int* data = randomData(size);
    showData(data, size);
    delete [] data;

    return 0;
}