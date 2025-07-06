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

void generator(ll x, ll a, ll b, ll c, ll n, vector<ll>& nums) {
  nums[0] = x;
  repx(i, 1, n) nums[i] = (a * nums[i-1] + b) % c;
}

// use deque
void solve() {
  ll n, k; cin >> n >> k;
  ll x, a, b, c; cin >> x >> a >> b >> c;
  vector<ll> nums(n, 0); generator(x, a, b, c, n, nums);
  deque<ll> dq; // keep indices
  ll l = 0, r = 0, curr = 0;
  for (; r < k-1; ++r) {
    while (!dq.empty() && nums[dq.back()] > nums[r]) dq.pop_back();
    dq.push_back(r);
  }
  ll res = 0;
  // cout << res;
  for (; r < n; ++r) {
    // we dont need the any information prev that was more than the curr number
    while (!dq.empty() && nums[dq.back()] > nums[r]) dq.pop_back();

    dq.push_back(r);
    // cout << nums[dq.front()] << ln;
    res ^= nums[dq.front()];
    
    ++l;
    while (!dq.empty() && dq.front() < l) dq.pop_front();
  }
  cout << res << ln;
}

int main() {
  flash;
  solve();
  return 0;
}