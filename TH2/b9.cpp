#include <bits/stdc++.h>
using namespace std;

int N, K;
string s;

void generate(int pos, int onesUsed) {
    // Da dat du N ky tu
    if (pos == N) {
        if (onesUsed == K) {
            cout << s << "\n";
        }
        return;
    }

    int remaining = N - pos; // so vi tri con lai (ke ca vi tri pos)

    // Cat nhanh: neu so bit 1 con thieu > so vi tri con lai -> khong the du K
    if (K - onesUsed > remaining) return;
    // Cat nhanh: neu so bit 1 da dung du roi va van con vi tri phai la 0 het,
    // hoac so bit 1 con thieu < 0 -> khong hop le
    if (onesUsed > K) return;

    // Thu dat '0' truoc (de dam bao thu tu tu dien tang dan)
    s[pos] = '0';
    generate(pos + 1, onesUsed);

    // Sau do thu dat '1'
    if (onesUsed + 1 <= K) {
        s[pos] = '1';
        generate(pos + 1, onesUsed + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        cin >> N >> K;
        s.assign(N, '0');
        generate(0, 0);
    }

    return 0;
}