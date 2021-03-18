//
// Created by joseortiz9 on 3/08/21.
//
#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool areEqualLetters(char a, char b) {
    if ((isupper(a) && isupper(b)) || (islower(a) && islower(b)))
        return false;
    return ((tolower(a) == b) || (a == tolower(b)));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    vector<char> t(0);
    map<int, pair<char, int>> values;
    vector<int> indexes;
    int mayus = 1, lower = 1;
    for (int i=0; i<s.length(); i++) {
        if (islower(s[i])) {
            values[i] = make_pair(s[i], lower);
            lower += 1;
        } else {
            values[i] = make_pair(s[i], mayus);
            mayus += 1;
        }
    }

    for (int i=0; i<s.length(); i++) {
        if (!t.empty() && areEqualLetters(t.back(), s[i])) {
            if (isupper(s[i])) {
                indexes.push_back(values.at(i-1).second);
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