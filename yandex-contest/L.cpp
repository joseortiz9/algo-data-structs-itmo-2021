//
// Created by joseortiz9 on 06/05/21.
//
#include <iostream>
#include <vector>
#include <algorithm>

#define rep(i, n)    for (int i = 0; i < (int)n; i++)
#define repv(i, v, n) for (int i = (int)v; i < (int)n; i++)

using namespace std;

void solve() {
    const int sz = 150000;

    int n, k;
    int x[sz], y[sz], z[sz];

    cin >> n >> k;
    cerr << k << "\n";
    rep(i, n) cin >> x[i];
    if (k-- == 1) {
        rep(i, n) cout << x[i] << " ";
        return;
    }
    cerr << k << "\n";
    rep(i, n) {
        if (i % k)
            y[i] = min(x[i], y[i-1]);
        else
            y[i] = x[i];
    }
    x[n-1] = y[n-1];
    rep(i, n-1) {
        if ((n-1-i) % k)
            z[n-2-i] = min(x[n-2-i], z[n-1-i]);
        else
            z[n-2-i] = x[n-2-i];
    }
    repv(i, k, n) cout << min(y[i], z[i-k]) << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}