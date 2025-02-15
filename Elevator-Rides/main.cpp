#include <bits/stdc++.h>
using namespace std;
#define deb(x)  cerr<< #x << ": " << x << '\n'
#define debl(x) cerr<< #x << ": " << x << ' '
#define ll long long
#define pb push_back
#define fs first 
#define sc second
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define rep(i,n) for(int i=0;i<n;++i)
#define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i]
#define ln "\n"

const int MAXN = 20;
vector<pair<int, int>> dp;
int n, limit;
vector<int> nums;

//dp[i] min_rides, min_cost
//given the current mask whats the min cost to build it

pair<int,int> Fx(int mask){
  if(mask  == 0) return {0,0};
  pair<int,int> min_cost = {21,limit+1};
  for(int i = 0; i<n; ++i){
      if(mask & (1<<i)){
      int tmp_mask = mask ^ (1<<i);
      pair<int,int> cost = dp[tmp_mask];
      if(cost.sc + nums[i] <= limit) cost.sc += nums[i];
      else{cost.fs++; cost.sc = nums[i];}
      min_cost = min(min_cost, cost);
    }
  }
  return min_cost;
}
void solve() {
  cin >> n >> limit;
  nums.resize(n,0); input(nums, n);
  reverse(nums.begin(), nums.end());
  dp.resize(1<<n,{0,0});
  for(int mask = 0; mask < (1<<n); ++mask){
    dp[mask] = Fx(mask);
  }
  cout << dp[ (1<<n) -1].fs + (dp[ (1<<n) -1].sc != 0);
}

int main() {
  flash;
  solve();
  return 0;
}