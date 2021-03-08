//
// Created by joseortiz9 on 3/08/21.
//
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    vector<char> stack(0);
    map<char,int> v;
    int mayus = 1, lower = 1;
    for (char & i : s) {
        if (islower(i)) {
            v[i] = (lower);
            lower += 1;
        } else {
            v[i] = (mayus);
            mayus += 1;
        }
    }

    for (char & i : s) {
        if (!stack.empty() && (tolower(stack.back()) == tolower(i))) {
            stack.pop_back();
        } else {
            stack.push_back(i);
        }
    }

    if (stack.empty()) {
        cout << "Possible" << endl;
        for (auto &b : v) {
            if (islower(b.first)) break;
            cout << v.at(tolower(b.first)) << " ";
        }
    } else {
        cout << "Impossible";
    }
    return cout << "\n", 0;
}