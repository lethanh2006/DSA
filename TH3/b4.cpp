#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<vector<int>> a(n);
        a[0].resize(n);

        for (int i = 0; i < n; i++)
            cin >> a[0][i];

        for (int i = 1; i < n; i++) {
            a[i].resize(n - i);
            for (int j = 0; j < n - i; j++)
                a[i][j] = a[i - 1][j] + a[i - 1][j + 1];
        }

        for (int i = 0; i < n; i++) {
            cout << "[";
            for (int j = 0; j < a[i].size(); j++) {
                cout << a[i][j];
                if (j + 1 < a[i].size())
                    cout << " ";
            }
            cout << "]\n";
        }
    }

    return 0;
}