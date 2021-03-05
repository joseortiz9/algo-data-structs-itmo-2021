#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct V {
    int value;
    int depth;
};

void solve() {
    map<string, vector<V>> v;
    int d = 0;
    string line;
    string value[2];
    while(cin >> line) {
        if (line == "{") {
            d += 1;
            continue;
        }
        if (line == "}") {
            for (auto &p : v) {
                if (p.second.back().depth == d)
                    p.second.pop_back();
            }
            d -= 1;
            continue;
        }
        value[0] = line.substr(0, 1);
    }
}


int main() {
    solve();
}