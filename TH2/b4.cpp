#include <iostream>
#include <vector>

using namespace std;

int n, k;
int a[105];
int ans = 0;
int x[105]; // Lưu chỉ số các phần tử được chọn

void Try(int i) {
    for (int j = x[i - 1] + 1; j <= n; ++j) {
        if (a[j] > a[x[i - 1]]) {
            x[i] = j;
            if (i == k) {
                ans++;
            } else {
                Try(i + 1);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (cin >> n >> k) {
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        a[0] = -1; // Khởi tạo giá trị nhỏ hơn mọi số trong dãy (vì a[i] > 0)
        x[0] = 0;  // Vị trí bắt đầu

        Try(1);

        cout << ans << "\n";
    }

    return 0;
}