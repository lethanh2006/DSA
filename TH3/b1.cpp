#include <bits/stdc++.h>
using namespace std;

int a[8][8];
bool col[8], d1[15], d2[15];
int ans;

void backtrack(int row, int sum) {
    if (row == 8) {
        ans = max(ans, sum);
        return;
    }

    for (int c = 0; c < 8; c++) {
        int x = row - c + 7;
        int y = row + c;

        if (!col[c] && !d1[x] && !d2[y]) {
            col[c] = d1[x] = d2[y] = true;

            backtrack(row + 1, sum + a[row][c]);

            col[c] = d1[x] = d2[y] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int test = 1; test <= T; test++) {
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                cin >> a[i][j];

        memset(col, false, sizeof(col));
        memset(d1, false, sizeof(d1));
        memset(d2, false, sizeof(d2));

        ans = 0;
        backtrack(0, 0);

        cout << "Test " << test << ": " << ans << '\n';
    }

    return 0;
}