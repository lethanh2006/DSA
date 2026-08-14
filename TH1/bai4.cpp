#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    if (!(cin >> t)) return 0;

    while (t--) {
        ll n, m;
        cin >> n >> m;

        set<ll> union_set;
        set<ll> a_set;
        set<ll> inter_set;

        for (ll i = 0; i < n; i++) {
            ll x;
            cin >> x;
            union_set.insert(x);
            a_set.insert(x);
        }

        for (ll i = 0; i < m; i++) {
            ll x;
            cin >> x;
            union_set.insert(x);
            if (a_set.count(x)) {
                inter_set.insert(x);
            }
        }

        for (ll x : union_set) {
            cout << x << " ";
        }
        cout << "\n";

        for (ll x : inter_set) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}
