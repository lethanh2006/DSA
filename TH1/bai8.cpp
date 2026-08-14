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
        vector<ll> a(n);
        map<ll, ll> freq;

        for (ll i = 0; i < n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }

        sort(a.begin(), a.end(), [&](ll u, ll v) {
            if (freq[u] != freq[v]) {
                return freq[u] > freq[v];
            }
            return u < v;
        });

        for (ll i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
