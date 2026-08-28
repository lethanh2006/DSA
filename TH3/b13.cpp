#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using i128 = __int128_t;

ll primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
ll ans;

void Try(int pos, int rem, int maxExp, ll cur) {
    if (rem == 1) {
        ans = min(ans, cur);
        return;
    }

    if (pos >= 16) return;

    i128 val = cur;

    for (int e = 1; e <= maxExp; e++) {
        val *= primes[pos];

        if (val > ans || val > (ll)1e18)
            break;

        if (rem % (e + 1) == 0) {
            Try(pos + 1, rem / (e + 1), e, (ll)val);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        if (N == 1) {
            cout << 1 << '\n';
            continue;
        }

        ans = (ll)1e18;
        Try(0, N, 60, 1);

        cout << ans << '\n';
    }

    return 0;
}