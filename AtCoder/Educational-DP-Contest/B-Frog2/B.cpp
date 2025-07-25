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
int INF=int(1e9);
bool valid(int x,int y,int n,int m){return x>=0 && x<n && y>=0 && y<m;}
int powMod(int a,int n){ ll ans=1;for(int i=1;i<=n;i++){ ans=(ans*a)%MOD;}return ans%MOD; }

void solve() {
  int n, k; cin >> n >> k;
  vector<ll> nums(n, 0), dp(n, INF);
  for(int i =0 ; i < n; ++i) {
    cin >> nums[i];
  }
  dp[0] = 0; dp[1] = abs(nums[1] - nums[0]);
  
  for(int i = 2; i < n; ++i) {
    for (int j = i-1; j>=max(0,i-k); --j) {
      dp[i] = min(
        dp[i],
        abs(nums[i] - nums[j]) + dp[j]
      );
    }
  }
  
  cout << dp[n-1] << "\n";
}

int main() {
  flash;
  solve();
  return 0;
}