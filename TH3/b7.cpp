#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a, cur;
vector<vector<int>> res;

void Try(int pos, int sum) {
    if (sum == k) {
        res.push_back(cur);
        return;
    }

    for (int i = pos; i < n; i++) {
        if (sum + a[i] > k) break;

        cur.push_back(a[i]);
        Try(i + 1, sum + a[i]);
        cur.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        cin >> n >> k;

        a.resize(n);
        for (int &x : a) cin >> x;

        sort(a.begin(), a.end());

        cur.clear();
        res.clear();

        Try(0, 0);

        sort(res.begin(), res.end());

        if (res.empty()) {
            cout << -1;
        } else {
            for (int i = 0; i < (int)res.size(); i++) {
                if (i) cout << " ";

                cout << "[";
                for (int j = 0; j < (int)res[i].size(); j++) {
                    if (j) cout << " ";
                    cout << res[i][j];
                }
                cout << "]";
            }
        }

        cout << '\n';
    }

    return 0;
}