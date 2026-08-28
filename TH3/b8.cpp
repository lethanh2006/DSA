#include <bits/stdc++.h>
using namespace std;

int n, k, target;
vector<int> a, bucket;

bool Try(int idx) {
    if (idx == n) return true;

    for (int i = 0; i < k; i++) {
        if (bucket[i] + a[idx] <= target) {
            bucket[i] += a[idx];

            if (Try(idx + 1)) return true;

            bucket[i] -= a[idx];
        }

        if (bucket[i] == 0) break;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        cin >> n >> k;

        a.resize(n);
        int sum = 0;

        for (int &x : a) {
            cin >> x;
            sum += x;
        }

        if (k > n || sum % k != 0) {
            cout << 0 << '\n';
            continue;
        }

        target = sum / k;

        if (target == 0) {
            cout << 1 << '\n';
            continue;
        }

        sort(a.rbegin(), a.rend());

        if (a[0] > target) {
            cout << 0 << '\n';
            continue;
        }

        bucket.assign(k, 0);

        cout << (Try(0) ? 1 : 0) << '\n';
    }

    return 0;
}