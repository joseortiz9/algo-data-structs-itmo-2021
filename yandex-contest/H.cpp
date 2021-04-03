//
// Created by joseortiz9 on 02/04/21.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, k, sum = 0;
    cin >> n >> k;
    vector<int> v(n);
    for (int &x : v) cin >> x;
    sort(v.rbegin(), v.rend());
    for (int i = 0; i < n; i++)
        if ((i+1) % k != 0) sum += v.at(i);
    cout << sum << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}