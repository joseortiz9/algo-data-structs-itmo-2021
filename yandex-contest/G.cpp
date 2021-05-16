//
// Created by joseortiz9 on 3/08/21.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct letter {
    char ch;
    int weight;
    int amount;
};

bool by_asc_weight(const letter &a, const letter &b) {
    return a.weight < b.weight;
}

void solve() {
    string s; cin >> s;
    vector<letter> v;
    map<char, int> m;
    int w;
    for (char i = 'a'; i <= 'z'; i++) {
        cin >> w;
        if (s.find(i) != string::npos)
            v.push_back({i, w, 0});
    }
    for (char & i : s) m[i]++;
    for (auto & i : v) i.amount = m[i.ch];

    sort(v.begin(), v.end(), by_asc_weight);

    string r;
    for (auto i : v) {
        if (i.amount >= 2) {
            r.insert(0, 1, i.ch);
            r.insert(r.size(), 1,  i.ch);
            int k = i.amount-2;
            r.insert(r.size()/2, k, i.ch);
        } else if (i.amount == 1) {
            r.insert(r.size()/2, 1, i.ch);
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