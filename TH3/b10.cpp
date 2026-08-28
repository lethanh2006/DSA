#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        long long S;
        cin >> n >> S;

        vector<long long> a(n);
        for (auto &x : a) cin >> x;

        int n1 = n / 2;
        int n2 = n - n1;

        unordered_map<long long, int> mp;

        for (int mask = 0; mask < (1 << n1); mask++) {
            long long sum = 0;
            int cnt = 0;

            for (int i = 0; i < n1; i++) {
                if (mask & (1 << i)) {
                    sum += a[i];
                    cnt++;
                }
            }

            if (sum <= S) {
                if (!mp.count(sum))
                    mp[sum] = cnt;
                else
                    mp[sum] = min(mp[sum], cnt);
            }
        }

        int ans = INT_MAX;

        for (int mask = 0; mask < (1 << n2); mask++) {
            long long sum = 0;
            int cnt = 0;

            for (int i = 0; i < n2; i++) {
                if (mask & (1 << i)) {
                    sum += a[n1 + i];
                    cnt++;
                }
            }

            if (sum > S) continue;

            long long need = S - sum;

            if (mp.count(need))
                ans = min(ans, cnt + mp[need]);
        }

        cout << (ans == INT_MAX ? -1 : ans) << '\n';
    }

    return 0;
}