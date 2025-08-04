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
  // ans from (i + 1, j) or (i, j - 1)
  // dp[i][i] = base case
  int N; cin >> N;
  vector<ll> nums(N, 0); rep(i, N) cin >> nums[i];
  vector<vl> dp(N, vl(N, 0));

  for (int i = 0; i < N; ++i) dp[i][i] = nums[i];
  
  for (int i = N-2; i >= 0; --i) {
    for (int j = 1; j < N; ++j) {
      if (i >= j) continue;
      dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1]);
    }
  }
  
  cout << dp[0][N-1];
}

int main() {
  flash;
  solve();
  return 0;
}