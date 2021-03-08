#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool e;

bool solve(string a, bool p) {
    if (!p) return false;
    if (a.empty()) return true;
    e = false;
    for (size_t i = 0; i < a.size(); i++) {
        if (i+1 < a.size() && (tolower(a[i]) == tolower(a[i + 1]))) {
            a.erase(a.begin()+i, a.begin()+i+2);
            e = true;
            break;
        }
    }
    return solve(a, e);
}

int main() {
    string s; cin >> s;
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
    bool p = solve(s, true);
    cout << ((p) ? "Possible" : "Impossible") << endl;
    if (p) {
        for (auto &b : v) {
            if (islower(b.first)) break;
            cout << v.at(tolower(b.first)) << " ";
        }
    }
}