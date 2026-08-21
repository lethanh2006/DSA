#include <iostream>
#include <vector>

using namespace std;

int n;
int a[20];

void printSolution() {
    // Gán nửa sau đối xứng với nửa đầu
    for (int i = 1; i <= n / 2; ++i) {
        a[n - i + 1] = a[i];
    }
    
    // In kết quả theo định dạng các phần tử cách nhau một khoảng trống
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << (i == n ? "" : " ");
    }
    cout << "\n";
}

void backtrack(int i, int limit) {
    for (int j = 0; j <= 1; ++j) {
        a[i] = j;
        if (i == limit) {
            printSolution();
        } else {
            backtrack(i + 1, limit);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (cin >> n) {
        int half = (n + 1) / 2;
        backtrack(1, half);
    }

    return 0;
}