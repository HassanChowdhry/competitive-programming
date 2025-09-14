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
double powMod(double a,double n){ double ans=1;for(int i=1;i<=n;i++){ ans=(ans*a);}return ans; }

void solve() {
  double n; cin >> n;
  vector<double> s(n); for (int i =0; i < n; ++i) cin >> s[i];
  double res = 0;
  double exp = (4.0)/(5.0);
  for (int i = 0; i < n; ++i) {
    double x = powMod(exp, (double)i);
    // cout << x << " " << s[i] << ln;
    res += (s[i] * x);
  }

  res = res * (1.0/5.0);
  double res2 = 0;
  for (int i = 0; i < n; ++i) {
    double p = 0.0;
    double curr = 0;
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      double x = powMod(exp, p);
      curr += (s[j] * x);
      ++p;
    }
    // cout << ln;
    // cout << res2 << ln;
    curr = curr * (1.0/5.0);
    res2 += curr;
  }
  // cout << res2;
  res2 /= (n);
  cout << fixed << setprecision(6) << res << ln;
  cout << fixed << setprecision(6) << res2 << ln;

}

int main() {
  flash;
  // int t; cin >> t;
  // rep(i, t) 
  solve();
  return 0;
}