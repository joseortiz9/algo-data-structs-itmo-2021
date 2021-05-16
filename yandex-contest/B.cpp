//
// Created by joseortiz9 on 3/08/21.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

vector<pair<char, int>> values, t(0);

bool areEqualLetters(char a, char b) {
    if ((isupper(a) && isupper(b)) || (islower(a) && islower(b)))
        return false;
    return ((tolower(a) == b) || (a == tolower(b)));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    int mayus = 1, lower = 1;
    for (char & i : s) {
        if (islower(i)) {
            values.emplace_back(i, lower);
            lower += 1;
        } else {
            values.emplace_back(i, mayus);
            mayus += 1;
        }
    }

    vector<int> indexes(values.size()/2, 0);
    for (auto & value : values) {
        if (!t.empty() && areEqualLetters(t.back().first, value.first)) {
            if (isupper(value.first)) {
                indexes[value.second-1] = t.back().second;
            } else {
                indexes[t.back().second-1] = value.second;
            }
            t.pop_back();
        } else {
            t.push_back(value);
        }
    }

    if (!t.empty()) {
        cout << "Impossible" << endl;
        return 0;
    }
    cout << "Possible" << endl;
    for (int &i : indexes) cout << i << " ";
    cout << endl;
    return 0;
}