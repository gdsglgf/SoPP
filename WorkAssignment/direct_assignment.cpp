#include <stdio.h>

int main() {
    int size = 10;
    printf("Directed Assignment Method:\n");
    int i;
    for (i = 0; i < size; ++i) {
        printf("%d->%d->%d\n", i, i, size - 1 - i);
    }

    return 0;
}