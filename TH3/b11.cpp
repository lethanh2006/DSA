#include <bits/stdc++.h>
using namespace std;

bool isValid(const string &s) {
    if (s.size() <= 1) return false; 
    int bal = 0;
    for (char c : s) {
        if (c == '(') bal++;
        else if (c == ')') {
            bal--;
            if (bal < 0) return false;
        }
    }
    return bal == 0;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);


        int left = 0, right = 0;
        for (char c : s) {
            if (c == '(') left++;
            else if (c == ')') {
                if (left > 0) left--;
                else right++;
            }
        }

        set<string> results;

        function<void(int,int,int,int,string)> dfs =
        [&](int idx, int lrem, int rrem, int balance, string cur) {
            if (idx == (int)s.size()) {
                if (lrem == 0 && rrem == 0 && balance == 0) {
                    if (isValid(cur)) results.insert(cur);
                }
                return;
            }

            char c = s[idx];

          
            if ((c == '(' && lrem > 0) || (c == ')' && rrem > 0)) {
                dfs(idx + 1, lrem - (c=='(' ? 1:0), rrem - (c==')' ? 1:0), balance, cur);
            }


            cur.push_back(c);
            if (c != '(' && c != ')') {
                dfs(idx + 1, lrem, rrem, balance, cur);
            } else if (c == '(') {
                dfs(idx + 1, lrem, rrem, balance + 1, cur);
            } else { 
                if (balance > 0)
                    dfs(idx + 1, lrem, rrem, balance - 1, cur);
            }
        };

        dfs(0, left, right, 0, "");

        if (results.empty()) {
            cout << -1 << "\n";
        } else {
            bool first = true;
            for (auto &r : results) {
                if (!first) cout << " ";
                first = false;
                cout << r;
            }
            cout << "\n";
        }
    }
    return 0;
}