#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fs first 
#define sc second 
#define all(a) a.begin(),a.end()
#define mod(num, n) (num % n + n) % n
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define test int t;cin>>t;while(t--)
#define rep(i,n) for(int i=0;i<n;++i)
#define repx(i,x,n) for(int i=x;i<n;++i)
#define per(i,n) for(int i=n-1;i>=0;--i)
#define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i]
#define rem(mp, el) if(mp[el]==0)mp.erase(el)
#define ln "\n"
#define vi vector<int>
#define vl vector<ll>
int MOD=1000000007;
bool valid(int x,int y,int n,int m){return x>=0 && x<n && y>=0 && y<m;}
int powMod(int a,int n){ ll ans=1;for(int i=1;i<=n;i++){ ans=(ans*a)%MOD;}return ans%MOD; }

void solve() {
  int n, t, m; cin >> n >> t >> m;
  string s; cin >> s;

  vector<vector<int>> suf(26, vector<int>(n));
  
  for (int j = 0; j <= 25; ++j) {
    string x = s;
    for (int i = 0; i < n; ++i) {
      x[i] = (((x[i] - 'A') + j) % 26) + 'A';
    }
    // cout << x << ln;
    suf[j][n-1] = x[n-1]-'A'+1;
    for (int i = n-2; i >= 0; --i) suf[j][i] = suf[j][i + 1] + (x[i]-'A'+1);
  }

  int cn = n, p = 0;
  for (int i = 0; i < t; ++i) {
    int y = ((suf[i%26][p]) % m) % cn;
    // cout << y;
    int x = y + p; // new len
    // cout << suf[i][p] + (i * cn) << " " << m << " " << cn << " " << y << ln;
    cn -= y;
    p = x;
  }     

  // cout << cn << " " << p << ln;
  for (int i = p; i < p + cn; ++i) {
    int c = s[i] - 'A';
    c = ((c + t) % 26);
    cout << (char)(c + 'A');
  }
}

int main() {
  flash;
  // int t; cin >> t;
  // rep(i, t) 
  solve();
  return 0;
}