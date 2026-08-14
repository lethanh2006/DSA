#include <bits/stdc++.h>
using namespace std;
#define ll long long

void merge(vector<ll>& a, ll l, ll m, ll r) {
    ll n1 = m - l + 1;
    ll n2 = r - m;

    vector<ll> L(n1), R(n2);

    for (ll i = 0; i < n1; i++) L[i] = a[l + i];
    for (ll j = 0; j < n2; j++) R[j] = a[m + 1 + j];

    ll i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<ll>& a, ll l, ll r) {
    if (l < r) {
        ll m = l + (r - l) / 2;

        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);

        merge(a, l, m, r);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    if (!(cin >> t)) return 0;

    while (t--) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        mergeSort(a, 0, n - 1);

        for (ll i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
