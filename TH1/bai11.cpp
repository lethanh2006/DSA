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
        bool have_swap = false;

        for (ll j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                have_swap = true;
            }
        }

      
        if (!have_swap) {
            break;
        }


        cout << "Buoc " << i + 1 << ":";
        for (ll j = 0; j < n; j++) {
            cout << " " << a[j];
        }
        cout << "\n";
    }

    return 0;
}