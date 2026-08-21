#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, W;
    cin >> N >> W;

    vector<int> c(N + 1); // gia tri
    vector<int> a(N + 1); // trong luong

    for (int i = 1; i <= N; i++)
        cin >> c[i];

    for (int i = 1; i <= N; i++)
        cin >> a[i];

    // dp[i][w] = gia tri lon nhat khi xet i vat
    // voi suc chua w
    vector<vector<long long>> dp(
        N + 1,
        vector<long long>(W + 1, 0)
    );

    for (int i = 1; i <= N; i++) {
        for (int w = 0; w <= W; w++) {

            // Khong chon vat i
            dp[i][w] = dp[i - 1][w];

            // Chon vat i
            if (a[i] <= w) {
                dp[i][w] = max(
                    dp[i][w],
                    dp[i - 1][w - a[i]] + c[i]
                );
            }
        }
    }

    // FOPT
    cout << dp[N][W] << '\n';

    // Truy vet XOPT
    vector<int> x(N + 1, 0);

    int w = W;

    for (int i = N; i >= 1; i--) {
        if (a[i] <= w &&
            dp[i][w] == dp[i - 1][w - a[i]] + c[i] &&
            dp[i][w] > dp[i - 1][w]) {

            x[i] = 1;
            w -= a[i];
        }
    }

    // In XOPT
    for (int i = 1; i <= N; i++) {
        cout << x[i];
        if (i < N) cout << ' ';
    }

    return 0;
}