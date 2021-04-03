//
// Created by joseortiz9 on 3/08/21.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool by_bigger_order(const string& first, const string& second) {
    return first+second > second+first;
}

void solve() {
    string line;
    vector<string> v;
    while(cin >> line) v.push_back(line);
    sort(v.begin(), v.end(), by_bigger_order);
    for (auto it = v.begin(); it < v.end(); it++)
        cout << *it;
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}