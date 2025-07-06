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
int MOD=1000000007;
bool valid(int x,int y,int n,int m){return x>=0 && x<n && y>=0 && y<m;}
int powMod(int a,int n){ ll ans=1;for(int i=1;i<=n;i++){ ans=(ans*a)%MOD;}return ans%MOD; }

int sub(int node, vector<int>& res, map<int, vector<int>>& children) {
  if (children[node].empty()) { res[node] = 0; return 1; }
  int total = 0;
  for (int child: children[node]) {
    total += sub(child, res, children);
  }
  res[node] = total;
  return total + 1;
}
void solve() {
  int n, num; cin >> n;
  map<int, vector<int>> mp;
  vector<int> res(n + 1);
  mp[1] = {};
  for (int i = 2; i <= n; ++i) {
    cin >> num;
    mp[num].pb(i);
  }

  sub(1, res, mp);

  repx(i, 1, n + 1) cout << res[i] << " ";
}

int main() {
  flash;
  solve();
  return 0;
}