#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    if (!(cin >> t)) return 0;

    while (t--) {
        ll n;
        cin >> n;

        ll cnt[3] = {0};
        for (ll i = 0; i < n; i++) {
            ll x;
            cin >> x;
            cnt[x]++;
        }


        for (ll i = 0; i < 3; i++) {
            while (cnt[i]--) {
                cout << i << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
