//
// Created by joseortiz9 on 3/08/21.
//
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int binarySearch(vector<int> v, int l, int r, int k) {
    if (r > l + 1) {
        int mid = (l + r) / 2;
        int counter = 1;
        for(int next = 0, prev = 0; next < v.size(); next++) {
            if (v.at(next) - v.at(prev) >= mid) {
                counter++;
                prev = next;
            }
        }
        if (counter >= k) return binarySearch(v, mid, r, k);
        else return binarySearch(v, l, mid, k);
    }
    return l;
}

void solve() {
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (int &x : v) cin >> x;
    cout << binarySearch(v, 0, INT_MAX, k) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}