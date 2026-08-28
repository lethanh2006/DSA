#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    string s;
    if (!(cin >> s)) return;
    sort(s.begin(), s.end());
    do {
        cout << s << " ";
    } while (next_permutation(s.begin(), s.end()));
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