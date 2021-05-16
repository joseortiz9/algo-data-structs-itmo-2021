//
// Created by joseortiz9 on 06/05/21.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define parent(i) ((int)i-1) >> 1
#define left(i) ((int)i << 1) + 1
#define right(i) ((int)i << 1) + 2

const int sz = 100000;

using namespace std;

int n, k, p, l=0;
int indices[sz], h[sz], s[5*sz];
vector<int> foo[sz];

void swp(int a, int b) {
    swap(h[a], h[b]);
    swap(indices[h[a]], indices[h[b]]);
}

int empty(int a) {
    return foo[h[a]].empty();
}

int front(int a) {
    return foo[h[a]].front();
}

int better(int a, int b) {
    if (!empty(a) && !empty(b)) {
        return front(a) > front(b);
    } else {
        return empty(a) && !empty(b);
    }
}

void up(int a) {
    for (;a && better(a , parent(a));) {
        swp(a, parent(a));
        a = parent(a);
    }
}

void down(int a) {
    for (;;) {
        int b = a;
        if (left(b) < l && better(left(b), a)) {
            a = left(b);
        }
        if (right(b) < l && better(right(b), a)) {
            a = right(b);
        }
        if (a != b) swp(a, b);
        else break;
    }
}

void push(int item) {
    indices[item] = l;
    h[l] = item;
    up(l++);
}

void pop() {
    swp(0, --l);
    indices[h[l]] = -1;
    down(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    cin >> k;
    cin >> p;
    for (int i = 0; i < p; i++) {
        cin >> s[i];
        s[i] -= 1;
        foo[s[i]].push_back(i);
    }
    int res = 0;
    memset(indices, -1, n * sizeof(int));
    for (int i = 0; i < p; i++) {
        foo[s[i]].erase(foo[s[i]].begin());
        if (indices[s[i]] != -1) {
            up(indices[s[i]]);
            continue;
        }
        if (l >= k) pop();
        push(s[i]);
        res++;
    }
    cout << res;
    return 0;
}