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
  // how many 3s in 1000, 5s in 1000 - LCM(3, 5) -> PYTHON WILL FIX THIS
  ll n; cin >> n; --n;
  ll t = 3, f = 5, lcm = 15;

  ll x = n / 5;
  x = ((x * (x + 1)) / 2);
  x*=5;

  ll y = n / 3;
  y = ((y * (y + 1)) / 2);
  y*=3;

  ll z = n / 15;
  z = ((z * (z + 1)) / 2);
  z*=15;

  cout << (x + y - z);

  // ll res =0;


}

int main() {
  flash;
  // int t; cin >> t;
  // rep(i, t) 
  solve();
  return 0;
}