#include <bits/stdc++.h>
using namespace std;

int N;
string s;

// pos       : vi tri dang xet
// consec6   : so chu so '6' lien tiep ngay truoc vi tri pos (tinh den ky tu vua dat)
// prevIs8   : ky tu ngay truoc vi tri pos co phai la '8' khong
void solve(int pos, int consec6, bool prevIs8) {
    // Da dat du N ky tu -> in ket qua
    if (pos == N) {
        cout << s << "\n";
        return;
    }

    // Vi tri dau tien bat buoc la '8'
    if (pos == 0) {
        s[0] = '8';
        solve(1, 0, true);
        return;
    }

    // Vi tri cuoi cung bat buoc la '6'
    if (pos == N - 1) {
        if (consec6 + 1 <= 3) { // khong qua 3 chu so 6 lien tiep
            s[pos] = '6';
            solve(pos + 1, consec6 + 1, false);
        }
        return;
    }

    // Cac vi tri o giua: thu '6' truoc (vi '6' < '8' trong thu tu tu dien)
    if (consec6 + 1 <= 3) {
        s[pos] = '6';
        solve(pos + 1, consec6 + 1, false);
    }

    // Sau do thu '8', chi khi ky tu truoc do khong phai la '8'
    if (!prevIs8) {
        s[pos] = '8';
        solve(pos + 1, 0, true);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    s.assign(N, '0');
    solve(0, 0, false);

    return 0;
}