#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int calculateCost(vector<int>& path, vector<vector<int>>& graph) {
    int cost = 0;
    int n = path.size();

    for (int i = 0; i < n - 1; i++)
        cost += graph[path[i]][path[i + 1]];

    cost += graph[path[n - 1]][path[0]];

    return cost;
}

int main() {
    int n = 4;

    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    vector<int> path = {0, 1, 2, 3};
    int minCost = INT_MAX;

    sort(path.begin() + 1, path.end());

    do {
        int cost = calculateCost(path, graph);
        minCost = min(minCost, cost);
    } while (next_permutation(path.begin() + 1, path.end()));

    cout << "Minimum travelling cost: " << minCost << endl;

    return 0;
}
