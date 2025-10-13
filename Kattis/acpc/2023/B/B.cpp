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
  string in;
  getline(cin,in);
  // cout<<s<<ln;

  string s; 
  for (char c : in) {
    if (c == 'R' || c == 'G' || c == 'Y' || c == 'B') 
    s += c;
  }

  // cout << s << ln;

  int n = s.size();
  if (n < 6) { cout << "eliminated" << ln; return; }
  if (s[0] != 'Y' || s[1] != 'R' || s[2] != 'R' || s[3] != 'G' || s[4] !=  'R') {
    cout << "eliminated" << ln; return;
  }

  // Y R G R
  if (s[n-1] != 'Y' || s[n-2] != 'R' || s[n - 3] != 'G' || s[n-4] != 'R') {
    cout << "eliminated" << ln; return;
  }

  int greens = 0;
  for (int i = 1; i < n - 1; ++i) {
    if (s[i] == 'G') ++greens;
  }

  if ((greens % 4) != 2) { cout << "eliminated" << ln; return; }
  if (greens > 2) {
    int reds = 0;
    int gf = -1, gl = -1;
    for (int i = 4; i < n - 3; ++i) {
      if (s[i] == 'G') {
        if (gf == -1) gf = i;
        gl = i;
      }
    }

    for (int i = gf; i < gl; ++i) {
      if (s[i] == 'R') {
        ++reds;
      }
    }

    if (reds % 3) {     
      cout << "eliminated" << ln; return;
    }
  }

  cout << "selected" << ln;
}

int main() {
  flash;
  int t; cin >> t;
  cin.ignore();
  rep(i, t) 
    solve();
  return 0;
}