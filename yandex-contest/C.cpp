//
// Created by joseortiz9 on 3/08/21.
//
#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve() {
    map<string, vector<pair<string, int>>> v;
    int d = 0;
    string line;
    pair<string, string> value;
    while(cin >> line) {
//        if (line == "ji") break;

        if (line == "{") {
            ++d;
        } else if (line == "}") {
            for (auto &p : v) {
                if (p.second.back().second == d)
                    p.second.pop_back();
            }
            --d;
        } else {
            value = make_pair(line.substr(0, line.find('=')), line.substr(line.find('=') + 1));

            // if the assign right val is a number
            if (isdigit(value.second[0]) || value.second[0] == '-') {
                if (v.count(value.first) > 0) {
                    v.at(value.first).push_back(make_pair(value.second, d));
                } else {
                    v.insert({value.first, {make_pair(value.second, d)}});
                }
            } else {
                if (v.count(value.second) == 0) {
                    v.insert({value.second, {make_pair("0", d)}});
                } else if (v.at(value.second).empty()) {
                    v.at(value.second).push_back(make_pair("0", d));
                }
                if (v.count(value.first) > 0) {
                    if (v.at(value.first).back() != v.at(value.second).back())
                        v.at(value.first).push_back(make_pair(v.at(value.second).back().first, d));
                } else {
                    v.insert({value.first, {make_pair(v.at(value.second).back().first, d)}});
                }
                cout << v.at(value.first).back().first << endl;
            }
        }
    }

//    for (auto &p : v) {
//        cout << p.first << endl;
//        for (auto & i : p.second) {
//            cout << "{" << i.first << ": " << to_string(i.second) << "}, ";
//        }
//        cout << "\n" << endl;
//    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}