#include <bits/stdc++.h>
using namespace std;

int n;
bool col[11], d1[25], d2[25];
long long ans;

void Try(int row) {
    if (row == n) {
        ans++;
        return;
    }

    for (int c = 0; c < n; c++) {
        int x = row - c + n;
        int y = row + c;

        if (!col[c] && !d1[x] && !d2[y]) {
            col[c] = d1[x] = d2[y] = true;

            Try(row + 1);

            col[c] = d1[x] = d2[y] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        cin >> n;

        memset(col, false, sizeof(col));
        memset(d1, false, sizeof(d1));
        memset(d2, false, sizeof(d2));

        ans = 0;
        Try(0);

        cout << ans << '\n';
    }

    return 0;
}