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
#define vpl vector<pair<ll, ll>>
int MOD=1000000007;
bool valid(int x,int y,int n,int m){return x>=0 && x<n && y>=0 && y<m;}
int powMod(int a,int n){ ll ans=1;for(int i=1;i<=n;i++){ ans=(ans*a)%MOD;}return ans%MOD; }

void solve() {
  ll n, num, mx = 0; cin >> n; 
  vl nums(n, 0); rep(i, n) { cin >> num, nums[i] = num; mx = max(mx, num); }
  map<ll, ll> dp;
  ll max_index = -1, max_num = -1, max_index_in_num = -1;

  rep(i, n) {
    num = nums[i];
    if (num == 0) { dp[num] = 1; continue; }
    if (dp[num] < dp[num - 1] + 1) {
      dp[num] = dp[num - 1] + 1;
      if (dp[num] > max_num) {
        max_num = dp[num];
        max_index = num;
        max_index_in_num = i;
      }
    }
  }

  ll curr = max_index, top = 0;
  vl res;
  for (ll i = max_index_in_num; i >= 0 && max_index > 0; --i) {
    if (max_index == nums[i]) {
      ++top;
      res.pb(i + 1);
      --max_index;
    }
  }
  
  cout << max_num << ln;
  per(i, top) cout << res[i] << " ";  
}

int main() {
  flash;
  solve();
  return 0;
}