#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    if (!(cin >> n)) return 0;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (ll i = 0; i < n - 1; i++) {
        ll min_idx = i;
        for (ll j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        swap(a[i], a[min_idx]);

        cout << "Buoc " << i + 1 << ":";
        for (ll j = 0; j < n; j++) {
            cout << " " << a[j];
        }
        cout << "\n";
    }

    return 0;
}
