#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;


void solve(){
    int n; cin >> n;
    int s = 0, m = 0, l = 0;
    while(n--){
        char c; int x; cin >> c >> x;
        if(c == 'S') s += x;
        if(c == 'M') m += x;
        if(c == 'L') l += x;
    }
    int ans = 0;
    ans += ceil(s/6.0) + ceil(m/8.0) + ceil(l/12.0);
    cout << ans << '\n';
}


int main(){
    ios();
    solve();
    return 0;
}