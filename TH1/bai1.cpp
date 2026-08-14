#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   int t ; cin >> t ;
   while(t--){
    int n ; cin >> n ;
    int a[n+4];
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    sort(a + 1 , a + n + 1);
    for(int i = 1 ; i <= n ; i ++) cout << a[i] << " ";
    cout<<'\n';
   }
}
