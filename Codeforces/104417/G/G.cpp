#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fs first 
#define sc second 
#define all(a) a.begin(),a.end()
#define mod(num, n) (num % n + n) % n
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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
  int n; cin >> n;
  vector<long long> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  map<long long, priority_queue<long long>> mp;

  for (int i = 1; i <= n; ++i) {
    long long v = i*1LL - a[i];
    mp[v].push(a[i]);
  }
  long long res = 0;
  for (auto [v, pq]: mp) {
    while (pq.size() > 1) {
      long long x = pq.top(); pq.pop();
      long long y = pq.top(); pq.pop();
      // cout << v << " " << x << " " << y << ln;
      if (x + y < 0) break;
      res += (x + y);
    }
  }

  cout << res << "\n";
}

int main() {
  flash;
  int t; cin >> t;
  while (t--)
    solve();
  return 0;
}