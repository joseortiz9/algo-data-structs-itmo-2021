//
// Created by joseortiz9 on 3/08/21.
//
#include <iostream>
using namespace std;

void solve() {
    int a, b, c, d, k, r, t;
    cin >> a >> b >> c >> d >> k;
    t=k;
    while (t--) {
        if (t+1==k) r = a * b;
        else r = r * b;
        if (r <= c) {
            r = 0;
            break;
        } else {
            r = r - c;
        }
        if (r > d) r = d;
    }
    cout << r;
}


int main() {
    solve();
}