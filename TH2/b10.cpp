#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(k);
    unordered_set<int> old_set;
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
        old_set.insert(a[i]);
    }

    // Tìm vị trí phần tử chưa đạt giới hạn từ phải sang trái
    int i = k - 1;
    while (i >= 0 && a[i] == n - k + i + 1) {
        i--;
    }

    // Nếu đã là tổ hợp cuối cùng thì tất cả K người đều được nghỉ
    if (i < 0) {
        cout << k << "\n";
        return;
    }

    // Sinh tổ hợp kế tiếp
    vector<int> b = a;
    b[i]++;
    for (int j = i + 1; j < k; ++j) {
        b[j] = b[j - 1] + 1;
    }

    // Đếm số người trong nhóm cũ không có mặt ở nhóm mới
    unordered_set<int> new_set(b.begin(), b.end());
    int count = 0;
    for (int x : a) {
        if (new_set.find(x) == new_set.end()) {
            count++;
        }
    }

    cout << count << "\n";
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