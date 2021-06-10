//
// Created by joseortiz9 on 09/06/21.
//
#include <iostream>
#include <cstring>

using namespace std;

int const x = 1001;

int N, M;
int res = 0;
int ADJ[x][x];

int T[x*x], F[4];

int calc(int A, int B) {
    F[0] = ADJ[A][B];
    F[1] = ADJ[A][M-1-B];
    F[2] = ADJ[N-1-A][B];
    F[3] = ADJ[N-1-A][M-1-B];

    for (int P : F) T[P]++;

    int ans = 0;
    for (int Q : F) {
        if (ans < T[Q]) ans = T[Q];
        T[Q] = 0;
    }
    return 4 - ans;
}

void solve() {
    cin >> N >> M;
    int shiftedN = N/2;
    int shiftedM = M/2;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> ADJ[i][j];

    for (int A = 0; A < shiftedN; A++) {
        if (N % 2 && ADJ[shiftedN][A] != ADJ[shiftedN][M-1-A]) {
            res += 1;
        }
        for (int B = 0; B < shiftedM; B++) {
            if (M % 2 && ADJ[B][shiftedM] != ADJ[N-1-B][shiftedM]) {
                res += 1;
            }
            res += calc(A, B);
        }
    }

    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
