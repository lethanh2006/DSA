#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        string x;
        cin >> x;

        int n = x.size();
        int carry = 1; // cong them 1

        for (int i = n - 1; i >= 0 && carry; i--) {
            if (x[i] == '0') {
                x[i] = '1';
                carry = 0;
            } else {
                x[i] = '0';
                carry = 1; // tiep tuc nho sang trai
            }
        }
        // Neu carry con du ra sau vong lap (tran), toan bo xau da thanh '0' -> dung yeu cau

        cout << x << "\n";
    }

    return 0;
}