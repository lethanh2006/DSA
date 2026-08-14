#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    if (!(cin >> t)) return 0;

    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end(), greater<ll>());
        for (ll i = 0; i < k; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
