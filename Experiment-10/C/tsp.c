#include <stdio.h>
#include <limits.h>

#define N 4

int graph[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int min(int a, int b) {
    return (a < b) ? a : b;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int calculateCost(int path[]) {
    int cost = 0;

    for (int i = 0; i < N - 1; i++)
        cost += graph[path[i]][path[i + 1]];

    cost += graph[path[N - 1]][path[0]]; // return to start
    return cost;
}

void permute(int path[], int l, int r, int *minCost) {
    if (l == r) {
        int cost = calculateCost(path);
        if (cost < *minCost)
            *minCost = cost;
        return;
    }

    for (int i = l; i <= r; i++) {
        swap(&path[l], &path[i]);
        permute(path, l + 1, r, minCost);
        swap(&path[l], &path[i]); // backtrack
    }
}

int main() {
    int path[N] = {0, 1, 2, 3};
    int minCost = INT_MAX;

    permute(path, 1, N - 1, &minCost);

    printf("Minimum travelling cost: %d\n", minCost);
    return 0;
}
