//
// Created by joseortiz9 on 08/06/21.
//
#include <iostream>
#include <cstring>

using namespace std;

int const sz = 111;
int A, B;
short SUN[sz], ADJ[sz][sz];

string BIN() {
    for (int k = 0; k < A; k++) {
        if (SUN[k] == -1)
            SUN[k] = 1;

        for (int l = k; l < A; l++)
            if (SUN[l] != -1)
                for (int m = k; m < A; m++)
                    if (ADJ[l][m]) {
                        if (SUN[m] == -1)
                            SUN[m] = not SUN[l];
                        else {
                            if (SUN[l] == SUN[m])
                                return "NO";
                        }
                    }

    }
    return "YES";
}

void solve() {
    cin >> A >> B;
    int n, m, times = B;
    while (times--) {
        cin >> n >> m;
        n--; m--;
        ADJ[n][m] = ADJ[m][n] = 1;
    }
    memset(SUN, -1, sizeof(SUN));
    cout << BIN() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
