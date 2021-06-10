//
// Created by joseortiz9 on 08/06/21.
//
#include <iostream>
#include <cstring>

using namespace std;

int const x = 111;

int sz, res = 0;
int O[x];
int ADJ[x][x];

void CYC(int A) {
    O[A] = 1;
    for (int B = 0; B < sz; B++)
        if (!O[B]) {
            if (ADJ[A][B]) CYC(B);
            else
            if (ADJ[B][A]) CYC(B);
        }
}

void DFS(int A) {
    O[A] = 1;
    for (int B = 0; B < sz; A++)
        if (ADJ[A][B] && !O[B])
            DFS(B);
}

void solve() {
    cin >> sz;
    for (int A, B = 0; B < sz; B++) {
        cin >> A;
        A -= 1;
        ADJ[A][B] = 1;
    }
    for (int A = 0; A < sz; A++)
        if (not O[A]) {
            bool FLAG = true;
            for (int B = 0; B < sz; B++)
                if (ADJ[B][A]) {
                    FLAG = false;
                    break;
                }
            if (FLAG) {
                sz += 1;
                DFS(A);
            }
        }
    for (int A = 0; A < sz; A++)
        if (O[A]) {
            res += 1;
            CYC(A);
        }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
