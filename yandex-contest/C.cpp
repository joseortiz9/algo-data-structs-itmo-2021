//
// Created by joseortiz9 on 3/08/21.
//
#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve() {
    map<string, vector<string>> v;
    vector<vector<string>>changed;
    vector<string> curr;
    string line;
    pair<string, string> value;
    while(cin >> line) {
        if (line == "{") {
            changed.push_back(curr);
            curr.clear();
        } else if (line == "}") {
            for (auto &p : curr) {
                if (v.at(p).size()==1){
                    v.at(p).back()="0";
                }
                else v.at(p).pop_back();
            }
            curr.clear();
            curr = changed.back();
            changed.pop_back();
        } else {
            value = make_pair(line.substr(0, line.find('=')), line.substr(line.find('=') + 1));
            // if the assign right val is a number
            if (!isdigit(value.second[0]) && value.second[0] != '-')
            {
                if (v.count(value.second) != 0){
                    value.second = v.at(value.second).back();
                }
                else{
                    value.second = "0";
                }
                cout<<value.second<<endl;
            }
            curr.push_back(value.first);
            if (v.count(value.first) != 0){
                v.at(value.first).push_back(value.second);
            }
            else {
                v.insert({value.first, {value.second}});
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}