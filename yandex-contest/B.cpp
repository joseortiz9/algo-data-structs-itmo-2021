//
// Created by joseortiz9 on 3/08/21.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

vector<char> t(0);
vector<pair<char, int>> values;
vector<int> indexes;

bool areEqualLetters(char a, char b) {
    if ((isupper(a) && isupper(b)) || (islower(a) && islower(b)))
        return false;
    return ((tolower(a) == b) || (a == tolower(b)));
}

int searchForOrder(int index, char letter) {
    int j = -1;
    for (int i = index; 0 <= i; i--) {
        if (values[i].second == -1) continue;
        if (letter == values[i].first) {
            j = values[i].second;
            values[i].second = -1;
            break;
        }
    }
    return j;
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

    int indexMayus;
    indexes.resize(s.size()/2, 0);
    for (int i = 0; i < s.size(); i++) {
        if (!t.empty() && areEqualLetters(t.back(), s[i])) {
            if (isupper(s[i])) {
                indexMayus = searchForOrder(i, s[i]);
                indexes[indexMayus-1] = searchForOrder(i, t.back());
            } else {
                indexMayus = searchForOrder(i, t.back());
                indexes[indexMayus-1] = searchForOrder(i, s[i]);
            }
            t.pop_back();
        } else {
            t.push_back(s[i]);
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