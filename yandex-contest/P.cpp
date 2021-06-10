//
// Created by joseortiz9 on 05/06/21.
//
#include <iostream>
#include <climits>
#include <cstring>

using namespace std;

int mid (int, int);

const int sz = 1000;
int N, w[sz][sz];
bool nd[sz][sz], vis[sz];

void DFS(int a, int x) {
    vis[a] = 1;
    for (int i = 0; i < N; i++) {
        if ((x ? nd[i][a] : nd[a][i]) && !vis[i]) DFS(i, x);
    }
}

int visitedAll() {
    for (int x = 0; x < N; x++) {
        if (!vis[x]) return 0;
    }
    return 1;
}

void solve() {
    cin >> N;
    for (int A = 0; A < N; A++)
        for (int B = 0; B < N; B++)
            cin >> w[A][B];
    int left = 0;
    int right = INT_MAX;
    while (left < right) {
        int Mid = mid(left, right);
        for (int A = 0; A < N; A++)
            for (int B = 0; B < N; B++)
                nd[A][B] = (Mid >= w[A][B]);
        memset(vis, 0, sizeof(vis));
        DFS(0, 0);
        int OK = 0;
        if (!visitedAll()) OK = 1;
        else {
            memset(vis, 0, sizeof(vis));
            DFS(0, 1);
            if (!visitedAll()) OK = 1;
        }
        if (OK) left = Mid + 1;
        else right = Mid;
    }
    cout << mid(left, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}

int mid(int a, int b) {
    return (a + b) / 2;
}