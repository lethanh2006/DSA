#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a, cur;
vector<vector<int>> res;

void Try(int pos, int sum) {
    for (int i = pos; i < n; i++) {
        cur.push_back(a[i]);

        if ((sum + a[i]) % 2 == 1)
            res.push_back(cur);

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
        cin >> n;
        a.resize(n);

        for (int &x : a)
            cin >> x;

        sort(a.begin(), a.end(), greater<int>());

        cur.clear();
        res.clear();

        Try(0, 0);

        sort(res.begin(), res.end());

        for (auto &v : res) {
            for (int i = 0; i < (int)v.size(); i++) {
                if (i) cout << ' ';
                cout << v[i];
            }
            cout << '\n';
        }
    }

    return 0;
}