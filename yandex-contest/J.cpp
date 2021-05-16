//
// Created by joseortiz9 on 06/05/21.
//
#include <iostream>
#include <deque>

#define rep(n) for (int i = 0; i < (int)n; i++)

using namespace std;

void solve() {
    int n;
    deque<int> p, q;
    cin >> n;
    rep(n) {
        char ch;
        int x;
        cin >> ch;
        if (ch == '+') {
            cin >> x;
            q.push_back(x);
        } else if (ch == '*') {
            cin >> x;
            q.push_front(x);
        } else {
            cout << p.front() << endl;
            p.pop_front();
        }
        if (p.size() < q.size()) {
            p.push_back(q.front());
            q.pop_front();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}