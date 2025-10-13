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
  int N, L; cin >> N >> L;
  string s; cin >> s;

  // for each level, I am going to go through each subtr possible substr and add that
  // dp[i][j] = ∑ dp[i-1][k] where k is a subtr of j
  
  // arr[subtr] 
  vector<string> a; a.pb(s);
  set<string> vis; vis.insert(s);
  for (int i = 0; i < N; ++i) {
    string curr = "";
    for (int j = i; j < N; ++j) {
      curr += s[j];
      if (!vis.count(curr)) { a.pb(curr); vis.insert(curr); }
    }
  }

  int AN = a.size();

  map<string, int> rev;
  for (int i = 0; i < AN; ++i) rev[a[i]] = i;
  
  map<int, vector<int>> adj;
  for (string check: a) {
    vector<int> b; b.pb(rev[check]);
    set<string> vis2; vis2.insert(check);
    int CN = check.size();
    for (int k = 0; k < CN; ++k) {
      string curr = "";
      for (int j = k; j < CN; ++j) {
        curr += check[j];
        if (!vis2.count(curr)) { b.pb(rev[curr]); vis2.insert(curr); }
      }
    }
    adj[rev[check]] = b;
  }

  vector<vl> dp(L + 1, vl(AN));
  for (int i = 0; i < AN; ++i) dp[0][i] = 1;
  // dp[0][0] = 1;

  // for (const auto& [key, value] : adj) {
  //   cout << a[key] << ": ";
  //   for (int in: value) cout << a[in] << ", ";
  //   cout << ln;
  // }
  // substr -> adj list | substr -> idx

  // dp[i][j] = ∑ dp[i-1][k] where k is a subtr of j

  for (int k = 1; k <= L; ++k) {
    for (int j = 0; j < AN; ++j) {
      // cout << a[j];
      for (int v: adj[j]) {
        dp[k][j] += dp[k-1][v] % MOD;
        dp[k][j] %= MOD;
      }
      // cout << ln;
    }
  }

  cout << dp[L][0] % MOD;
  
  // for (int i = 0; i <= L; ++i) cout << dp[i][0] << " ";



}

int main() {
  flash;
  // int t; cin >> t;
  // rep(i, t) 
  solve();
  return 0;
}