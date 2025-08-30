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

double dp[303][303][303];
int n;
double dfs(int i, int j , int k) {
  if (i == 0 && j == 0 && k == 0) return 0;
  if ( i < 0 || j < 0 || k < 0 ) return 0;

  if (dp[i][j][k] != 0) return dp[i][j][k];
  int N = i + j + k;
  double calc = (double)i/N * dfs(i-1, j, k) + (double)j/N * dfs(i+1, j-1, k) + (double)k/N*dfs(i,j+1,k-1) + (double)n/N;
  dp[i][j][k] = calc;
  return calc;
}

void solve() {
  int num; cin >> n;
  vi nums(4); rep(i, n) { cin >> num; ++nums[num]; }
  // dp[nums[1]][nums[2]][nums[3]] = 1;

  double res = dfs(nums[1], nums[2], nums[3]);
  cout << setprecision(10) << res;
}

int main() {
  flash;
  solve();
  return 0;
}