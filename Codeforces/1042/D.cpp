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
  int n; cin >> n;
  vector<int> cnt(n + 1, 0);
  vector<vi> adj(n + 1);
  
  // cout << n << ln;

  rep(_, n-1) {
    int u, v; cin >> u >> v;
    adj[u].pb(v); adj[v].pb(u);
    ++cnt[u]; ++cnt[v];
  }
  
  if (n <= 3) { cout << 0 << ln; return; }

  int leaves = 0;
  rep(i, n) if (cnt[i+1] == 1) ++leaves;

  // for every possible root
  int mx_leaves = 0;
  for (int i = 1; i <= n; ++i) {  
    // get the one with the max leaves
    int curr = 0;
    for (int child: adj[i]) if (cnt[child] == 1) ++curr;

    mx_leaves = max(mx_leaves, curr);
  }

  cout << leaves - mx_leaves << ln;
}

int main() {
  flash;
  int t; cin >> t;
  rep(i, t)
    solve();
  return 0;
}