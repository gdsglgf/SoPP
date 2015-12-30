#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Rotated Assignment Method:\n");
    int size = 10;
    
    int r = rand() % size;
    printf("r = %d\n", r);
    int i;
    for (i = 0; i < size; ++i) {
        int forward = (i + r) % size;   // 向前循环移动
        printf("%d->%d->%d->", i, forward, size - 1 - forward);

        int backward = (i - r + size) % size;   // 向后循环移动
        printf("%d->%d\n", backward, size - 1 - backward);
    }

    return 0;
}