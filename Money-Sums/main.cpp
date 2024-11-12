#include <bits/stdc++.h>
# define ll long long
# define pb push_back
# define all(a) a.begin(),a.end()
# define flash ios_base::sync_with_stdio(false);cin.tie(NULL);
# define test int t;cin>>t;while(t--)
# define loop(n) for(int i=0;i<n;i++)
# define loopx(x, n) for(int i=x;i<n;i++)
# define input(arr,n);for(int i=0;i<n;i++)cin>>arr[i];
# define nline "\n"
using namespace std;
int MOD=1000000007;
using namespace std;

// ! Not Implemeneted
void dfs(int idx, ll curr, int count, int n, vector<int>& nums, set<int>& visit, vector<int>& out) {
  if (idx > n) 
    { return; }
  
  if (count >= 2 && !visit.count(curr)) 
    { visit.insert(curr); out.pb(curr); }

  for (int i = idx; i < n; ++i) {
    dfs(i+1, curr + nums[i], ++count, n, nums, visit, out);
  }
}

int main() {
  int n; cin >> n;
  vector<int> nums(n); input(nums, n); sort(nums.begin(), nums.end());
  set<int> visit; vector<int> out;

  dfs(0, 0, 0, n, nums, visit, out);

  int m = out.size(); cout << m << nline; sort(out.begin(), out.end());
  loop(m) 
    { cout << out[i] << " "; }
  // cout << ;
}
