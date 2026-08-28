#include <bits/stdc++.h>
using namespace std;

int n, X;
vector<int> a, cur;
vector<vector<int>> res;

void Try(int pos, int sum) {
    if (sum == X) {
        res.push_back(cur);
        return;
    }

    for (int i = pos; i < n; i++) {
        if (sum + a[i] > X) break;

        cur.push_back(a[i]);
        Try(i, sum + a[i]);
        cur.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        cin >> n >> X;

        a.resize(n);
        for (int &x : a) cin >> x;

        sort(a.begin(), a.end());

        cur.clear();
        res.clear();

        Try(0, 0);

        if (res.empty()) {
            cout << -1;
        } else {
            for (auto &v : res) {
                cout << "[";
                for (int i = 0; i < (int)v.size(); i++) {
                    if (i) cout << " ";
                    cout << v[i];
                }
                cout << "]";
            }
        }

        cout << '\n';
    }

    return 0;
}