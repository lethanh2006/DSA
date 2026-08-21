#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> a;

void Try(int remain, int maxVal) {
    if (remain == 0) {
        cout << "(";
        for (int i = 0; i < a.size(); i++) {
            if (i > 0) cout << " ";
            cout << a[i];
        }
        cout << ") ";
        return;
    }

    for (int x = min(remain, maxVal); x >= 1; x--) {
        a.push_back(x);
        Try(remain - x, x);
        a.pop_back();
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        cin >> n;
        a.clear();

        Try(n, n);
        cout << '\n';
    }

    return 0;
}