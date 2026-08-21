#include <iostream>
#include <string>
using namespace std;

int n;
string s;

void Try(int i) {
    if (i == n) {
        cout << s << " ";
        return;
    }

    s.push_back('A');
    Try(i + 1);
    s.pop_back();

    s.push_back('B');
    Try(i + 1);
    s.pop_back();
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        cin >> n;
        s.clear();

        Try(0);
        cout << '\n';
    }

    return 0;
}