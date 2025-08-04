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
  int n, a, b, x, y;
  cin >> n >> a >> b;
  x = a, y = b;
  if (a < b) swap(a, b);
  

  if ((a > 0 && b == 0) || (a + b > n)) { cout << "NO" << ln; return; }

  cout << "YES" << ln; 
  if (a == 0 && b == 0) {
    for (int i = 1; i <= n; ++i) cout << i << " ";
    cout << ln;
    for (int i = 1; i <= n; ++i) cout << i << " ";
    cout << ln;
    return;
  }

  int i = n, j = n - b;
  vector<int> r1, r2;
  rep(_, a) {
    r1.pb(i); --i;
    r2.pb(j); --j;
  }
  i = n - a, j = n;
  rep(_, b) {
    r2.pb(j); --j;
    r1.pb(i); --i;
  }
  
  int rest = n - a - b;
  for (int i=1; i <= rest; ++i) { r1.pb(i); r2.pb(i); }
  
  if (x == a) {
    for (int i = 0; i < n; ++i) cout << r1[i] << " ";
    cout << ln;
    for (int i = 0; i < n; ++i) cout << r2[i] << " ";
    cout << ln;
  } else {
    for (int i = 0; i < n; ++i) cout << r2[i] << " ";
    cout << ln;
    for (int i = 0; i < n; ++i) cout << r1[i] << " ";
    cout << ln;
  }
}

int main() {
  flash;
  int t; cin >> t;
  rep(_, t) solve();
  return 0;
}