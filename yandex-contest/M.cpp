//
// Created by joseortiz9 on 05/06/21.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

const int maxn = 1000;

int n, m, a, b, c, d;
short int adj[maxn][maxn];

vector<vector<int>> world(maxn, vector<int>(maxn, INT_MAX));
int was[maxn][maxn];

void dijkstra(int A, int B) {
    priority_queue<pair<int, pair<int, int>>> HEAP;
    HEAP.push({(world[A][B] = 0), {A, B}});
    while (!HEAP.empty()) {
        A = HEAP.top().second.first;
        B = HEAP.top().second.second;
        HEAP.pop();
        if (was[A][B]) continue; else was[A][B] = 1;
        if (A > 0 and !was[A - 1][B] and adj[A - 1][B]) {
            if (world[A][B] + adj[A - 1][B] < world[A - 1][B])
                world[A - 1][B] = world[A][B] + adj[A - 1][B];
            HEAP.push({-world[A - 1][B], {A - 1, B}});
        } if (A < n - 1 and !was[A + 1][B] and adj[A + 1][B]) {
            if (world[A][B] + adj[A + 1][B] < world[A + 1][B])
                world[A + 1][B] = world[A][B] + adj[A + 1][B];
            HEAP.push({-world[A + 1][B], {A + 1, B}});
        } if (B > 0 and !was[A][B - 1] and adj[A][B - 1]) {
            if (world[A][B] + adj[A][B - 1] < world[A][B - 1])
                world[A][B - 1] = world[A][B] + adj[A][B - 1];
            HEAP.push({-world[A][B - 1], {A, B - 1}});
        } if (B < m - 1 and !was[A][B + 1] and adj[A][B + 1]) {
            if (world[A][B] + adj[A][B + 1] < world[A][B + 1])
                world[A][B + 1] = world[A][B] + adj[A][B + 1];
            HEAP.push({-world[A][B + 1], {A, B + 1}});
        }
    }
}

int COST = 0;
void print(int axis_x, int axis_y){
    if (world[axis_x][axis_y] == 0) return;
    else COST = world[axis_x][axis_y];

    char CH;
    if (axis_x > 0 and COST > world[axis_x - 1][axis_y]) {
        CH = 'S'; COST = world[axis_x - 1][axis_y];
    }
    if (axis_x < n - 1 and COST > world[axis_x + 1][axis_y]) {
        CH = 'N'; COST = world[axis_x + 1][axis_y];
    }
    if (axis_y > 0 and COST > world[axis_x][axis_y - 1]) {
        CH = 'E'; COST = world[axis_x][axis_y - 1];
    }
    if (axis_y < m - 1 and COST > world[axis_x][axis_y + 1]) {
        CH = 'W'; COST = world[axis_x][axis_y + 1];
    }
    switch (CH) {
        case 'S': print(axis_x - 1, axis_y); break;
        case 'N': print(axis_x + 1, axis_y); break;
        case 'E': print(axis_x, axis_y - 1); break;
        case 'W': print(axis_x, axis_y + 1); break;
    }
    putchar(CH);
}

void solve() {
    cin >> n;
    cin >> m;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++)
            if (s[j] == '.') adj[i][j] = 1;
            else if (s[j] == 'W') adj[i][j] = 2;
    }
    dijkstra(--a, --b);
    if (!was[c - 1][d - 1])
        cout << -1 << endl;
    else {
        cout << world[c - 1][d - 1] << endl;
        print(--c, --d);
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}