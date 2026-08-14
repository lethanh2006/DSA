#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t ;

    while (t--) {
        ll n;
        cin >> n;
        vector<ll> a(n + 1);
        for (ll i = 1; i <= n; i++) {
            cin >> a[i];
        }

        sort(a.begin() + 1, a.end());

        ll l = 1, r = n;
        while (l <= r) {
            if (l == r) {
                cout << a[r] << " ";
                break;
            }
            cout << a[r] << " " << a[l] << " ";
            r--;
            l++;
        }
        cout << "\n";
    }

    return 0;
}
