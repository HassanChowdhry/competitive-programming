#include <bits/stdc++.h>
# define ll long long
# define pb push_back
# define all(a) a.begin(),a.end()
# define flash ios_base::sync_with_stdio(false);cin.tie(NULL);
# define test int t;cin>>t;while(t--)
# define loop(n) for(int i=0;i<n;++i)
# define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i];
# define nline "\n"
using namespace std;
int MOD=1000000007;
bool valid(int x,int y,int n,int m){return x>=0 && x<n && y>=0 && y<m;}
int powMod(int a,int n){ ll ans=1;for(int i=1;i<=n;i++){ ans=(ans*a)%MOD;}return ans%MOD; }

int main() {
  int n, median_index, median; cin >> n;
  ll cost = 0;
  vector<int> nums(n); input(nums, n);
  sort(nums.begin(), nums.end());
  
  median_index = (int) ((n-1) / 2);
  median = nums[median_index];

  loop(n)
    { cost += abs(median - nums[i]); }
  
  cout << cost;
}