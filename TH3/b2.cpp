#include <iostream>
#include <vector>

using namespace std;

int n, k;
int a[25];
int cnt = 0;

bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

void Try(int i) {
    for (int j = a[i - 1] + 1; j <= n - k + i; ++j) {
        a[i] = j;
        if (i == k) {
            cnt++;
            if (isPrime(cnt)) {
                cout << cnt << ": ";
                for (int m = 1; m <= k; ++m) {
                    cout << a[m] << (m == k ? "" : " ");
                }
                cout << "\n";
            }
        } else {
            Try(i + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (cin >> n >> k) {
        Try(1);
    }
    return 0;
}