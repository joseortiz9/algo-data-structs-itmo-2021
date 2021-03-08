#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve() {
    map<string, vector<pair<int, int>>> v;
    int d = 0;
    string line;
    string value[2];
    while(cin) {
        if (line == "{") {
            d += 1;
            continue;
        }
        if (line == "}") {
            for (auto &p : v) {
                if (p.second.back().second == d)
                    p.second.pop_back();
            }
            d -= 1;
            continue;
        }
        value[0] = line.substr(0, line.find('='));
        value[1] = line.substr(line.find('=') + 1);

        //if the assign val is a number
        if (isdigit(value[1][0]) || value[1][0] == '-') {
            if (v.count(value[0]) > 0) {
                v.at(value[0]).push_back(make_pair(stoi(value[1]), d));
            } else {
                vector<pair<int, int>> v1{make_pair(stoi(value[1]), d)};
                v[value[0]] = v1;
            }
        } else {

        }
    }

    for (auto &p : v) {
        cout << p.first << endl;
        for (auto & i : p.second) {
            cout << "{" << to_string(i.first) << ": " << to_string(i.second) << "}, ";
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}