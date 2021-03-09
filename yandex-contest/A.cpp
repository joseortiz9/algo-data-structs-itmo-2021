//
// Created by joseortiz9 on 3/08/21.
//
#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int start, length, repeated = 1, prev = -1;
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == prev) {
            repeated++;

        }
    }

    cout << start << " " << start + length;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}