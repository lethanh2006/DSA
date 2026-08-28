#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<string> names;
vector<int> comb;

void go(int start) {
    if ((int)comb.size() == k) {
        for (int i = 0; i < k; i++) {
            cout << names[comb[i]];
            if (i + 1 < k) cout << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = start; i < (int)names.size(); i++) {
        comb.push_back(i);
        go(i + 1);
        comb.pop_back();
    }
}

int main() {
    cin >> n >> k;
    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    names = a;
    go(0);
    return 0;
}