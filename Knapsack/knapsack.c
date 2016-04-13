#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define SIZE 1000

int cost[SIZE];     // 物品体积
int value[SIZE];    // 物品价值
int f[SIZE];        // 备忘表, 只计算最大价值

int data[SIZE][SIZE];   // 备忘表, 可计算最大价值和选择的物品

int max(int a, int b) {
    return a > b ? a : b;
}

/**
计算0-1背包最大价值
@param n 物品数量
@param v 背包体积
*/
int zeroOnePack(int n, int v) {
    int i, j;
    memset(f, 0, SIZE * sizeof(int));
    for (i = 0; i < n; i++) {
        for (j = v; j >= cost[i]; j--) {
            f[j] = max(f[j], f[j - cost[i]] + value[i]);
        }
    }

    return f[v];
}

/*
递归输出0-1背包选择的物品
@param i 物品编号(从1开始)
@param j 背包体积
*/
void showZeroOnePackItem(int i, int j) {
    if (i <= 0) {
        return;
    }

    if (data[i][j] != data[i - 1][j]) {
        showZeroOnePackItem(i - 1, j - cost[i - 1]);
        printf("%d ", i);   // 物品i在背包中
    } else {
        showZeroOnePackItem(i - 1, j);
    }
}

/**
输出0-1背包最大价值以及选择的物品
@param n 物品数量
@param v 背包体积
*/
void fullZeroOnePack(int n, int v) {
    int i, j;
    for (i = 0; i <= v; i++) {
        data[0][i] = 0;
    }

    for (i = 0; i <= n; i++) {
        data[i][0] = 0;
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= v; j++) {
            if (j >= cost[i - 1]) {
                int r1 = data[i - 1][j - cost[i - 1]] + value[i - 1];  // 0-1背包
                data[i][j] = max(r1, data[i - 1][j]);
            } else {
                data[i][j] = data[i - 1][j];
            }
        }
    }

    printf("full 01 pack:%d\n", data[n][v]);
    printf("item list:\n");
    showZeroOnePackItem(n, v);
    printf("\n-------------\n");
}

/**
计算完全背包最大价值
@param n 物品数量
@param v 背包体积
*/
int completePack(int n, int v) {
    int i, j;
    memset(f, 0, SIZE * sizeof(int));
    for (i = 0; i < n; i++) {
        for (j = cost[i]; j <= v ; j++) {
            f[j] = max(f[j], f[j - cost[i]] + value[i]);
        }
    }
    return f[v];
}

/*
递归输出完全背包选择的物品
@param i 物品编号(从1开始)
@param j 背包体积
*/
void showCompletePackItem(int i, int j) {
    if (i <= 0) {
        return;
    }

    if (data[i][j] != data[i - 1][j]) {
        showCompletePackItem(i, j - cost[i - 1]);
        printf("%d ", i);   // 物品i在背包中
    } else {
        showCompletePackItem(i - 1, j);
    }
}

/**
输出完全背包最大价值以及选择的物品
@param n 物品数量
@param v 背包体积
*/
void fullCompletePack(int n, int v) {
    int i, j;
    for (i = 0; i <= v; i++) {
        data[0][i] = 0;
    }

    for (i = 0; i <= n; i++) {
        data[i][0] = 0;
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= v; j++) {
            if (j >= cost[i - 1]) {
                int r1 = data[i][j - cost[i - 1]] + value[i - 1];  // 完全背包
                data[i][j] = max(r1, data[i - 1][j]);
            } else {
                data[i][j] = data[i - 1][j];
            }
        }
    }

    printf("full comp pack:%d\n", data[n][v]);
    printf("item list:\n");
    showCompletePackItem(n, v);
    printf("\n-------------\n");
}


int main(int argc, char *argv[]) {
    int n, v, i, j;

    while (scanf("%d %d", &n, &v) != EOF) {
        printf("------%d %d\n", n, v);

        for (i = 0; i < n; i++) {
            scanf("%d %d", &cost[i], &value[i]);
            printf("%d %d\n", cost[i], value[i]);
        }

        printf("01 pack:%d\n", zeroOnePack(n, v));
        fullZeroOnePack(n, v);
        printf("comp pack:%d\n", completePack(n, v));
        fullCompletePack(n, v);
    }

    return 0;
}
