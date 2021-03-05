#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool solve(vector<char> a, bool p) {
    if (!p) return false;
    if (string(a.begin(), a.end()).empty()) return true;
    bool e = false;
    for (size_t i = 0; i < a.size(); i++) {
        if (i+1 < a.size() && (tolower(a[i]) == tolower(a[i + 1]))) {
            a.erase(a.begin()+i);
            a.erase(a.begin()+i);
            e = true;
            break;
        }
    }
    return solve(a, e);
}

int main() {
    string a;
    cin >> a;
    vector<char> v(a.begin(), a.end()), mayusVector;
    map<char, int> lowerMap;
    int mayus = 1, lower = 1;
    for (char & i : v) {
        if (islower(i)) {
            lowerMap[i] = lower;
            lower += 1;
        } else {
            mayusVector.push_back(i);
            mayus += 1;
        }
    }
    bool p = solve(v, true);
    cout << ((p) ? "Possible" : "Impossible") << endl;
    if (p) {
        for (char &i : mayusVector) {
            cout << lowerMap.at(tolower(i)) << " ";
        }
    }
}