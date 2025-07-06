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

int dfs(int node, int parent, vector<int>& dp, vector<vector<int>>& adj) {
  if (adj[node].size() == 1 && adj[node][0] == parent) {
    dp[node] = 0;
    return 1;
  }

  dp[node] = 0;
  int max1 = 0, max2 = 0;
  for (int edge: adj[node]) {
    if (edge == parent) continue;
    int temp = dfs(edge, node, dp, adj);

    if (temp > max1) {
      max2 = max1; max1 = temp;
    } else if (temp > max2) max2 = temp;
  }

  dp[node] = max1 + max2;
  return 1 + max(0, max(max1, max2));
}

void solve() {
  int n; cin >> n;
  vector<vector<int>> adj(n+1);
  vector<int> dp(n+1, 0);

  int a, b;
  rep(i, n-1) {
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }

  dfs(1, -1, dp, adj);
  int mx = 0;

  rep(j, n+1) mx = max(mx, dp[j]);
  
  cout << mx;
}

int main() {
  flash;
  solve();
  return 0;
}