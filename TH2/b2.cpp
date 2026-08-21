#include <iostream>
#include <vector>
using namespace std;

int n, K;
vector<int> a;
vector<int> cur;
int cnt = 0;

void Try(int i, int sum) {
    // Đã xét hết các phần tử
    if (i == n) {
        if (sum == K) {
            for (int j = 0; j < (int)cur.size(); ++j) {
                if (j > 0) cout << ' ';
                cout << cur[j];
            }
            cout << '\n';
            cnt++;
        }
        return;
    }

    // Vì các phần tử là số tự nhiên, tổng đã > K thì không cần xét tiếp
    if (sum > K) return;

    // 1. Không chọn a[i]
    Try(i + 1, sum);

    // 2. Chọn a[i]
    cur.push_back(a[i]);
    Try(i + 1, sum + a[i]);
    cur.pop_back();
}

int main() {
    cin >> n >> K;

    a.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    Try(0, 0);

    cout << cnt;

    return 0;
}