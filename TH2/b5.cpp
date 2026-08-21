#include <iostream>
using namespace std;

int n;
int a[10];
bool used[10];
int cnt = 0;

void Try(int i) {
    for (int j = 1; j <= n; j++) {
        if (!used[j]) {
            a[i] = j;
            used[j] = true;

            if (i == n) {
                cnt++;
                cout << cnt << ": ";
                for (int k = 1; k <= n; k++) {
                    cout << a[k];
                    if (k < n) cout << " ";
                }
                cout << '\n';
            } else {
                Try(i + 1);
            }

            used[j] = false;
        }
    }
}

int main() {
    cin >> n;
    Try(1);
    return 0;
}