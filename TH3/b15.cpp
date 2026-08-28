#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; (long long)i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<vector<int>> results;

        for (int mask = 1; mask < (1 << n); mask++) {
            vector<int> subset;
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    subset.push_back(a[i]);
                    sum += a[i];
                }
            }
            if (isPrime(sum)) {
                sort(subset.begin(), subset.end(), greater<int>());
                results.push_back(subset);
            }
        }

        sort(results.begin(), results.end()); 

        for (auto &r : results) {
            for (int i = 0; i < (int)r.size(); i++) {
                cout << r[i];
                if (i + 1 < (int)r.size()) cout << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}