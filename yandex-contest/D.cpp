//
// Created by joseortiz9 on 3/08/21.
//
#include <iostream>
using namespace std;

void solve() {
    long long a, b, c, d, k, r;
    cin >> a >> b >> c >> d >> k;
    if (a * b <= c) {
        cout << 0 << endl;
        return;
    }
    r = a * b - c;
    if (r == a) {
        cout << a << endl;
        return;
    } else if (r >= d) {
        cout << d << endl;
        return;
    }
    while (k--) {
        r = r * b - c;
        if (r < 0) {
            r = 0;
            break;
        }
        if (r >= d) {
            r = d;
            break;
        }
    }
    cout << r << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}