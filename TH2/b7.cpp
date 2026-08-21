#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    // Khởi tạo hoán vị lớn nhất: n, n-1, ..., 1
    for (int i = 0; i < n; ++i) {
        a[i] = n - i;
    }

    // Sinh các hoán vị theo thứ tự giảm dần (ngược)
    bool first = true;
    do {
        if (!first) cout << " ";
        for (int x : a) {
            cout << x;
        }
        first = false;
    } while (prev_permutation(a.begin(), a.end()));

    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }

    return 0;
}