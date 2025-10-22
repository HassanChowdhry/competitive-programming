#include <bits/stdc++.h>
#define deb(x) cerr << #x << ": " << x << '\n'
#define debl(x) cerr << #x << ": " << x << ' '
using namespace std;
void LSH() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n, t, m;
string f(string s){
    int sum = 0;
    for(char c : s) sum += c-'A'+1;
   // deb(sum);
    sum %= m;
    sum %= s.size();
    string ans = "";
   // deb(sum);
    for(int i = sum; i<s.size(); ++i){
        int x = s[i]-'A';
        x = (x+1)%26;
        char c = (x+'A');
        ans.push_back(c);
    } 
   // deb(ans);
    return ans;
}

void solve() {
    cin >> n >> t >> m;
    string s; cin >> s;
    //deb(s);
    while(t--){
        s = f(s);
    }
    cout << s << '\n';
}
int main() {
    LSH();
    solve();
}