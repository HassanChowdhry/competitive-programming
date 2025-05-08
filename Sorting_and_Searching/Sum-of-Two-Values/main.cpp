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

int main() {
  int n, target, num; cin >> n >> target;
  vector<pair<int, int>> nums(n);
  int l = 0, r = n-1; bool found = false;

  loop(n)
    { cin >> num; nums[i] = { num, i+1 }; } 
  sort(nums.begin(), nums.end());
  
  while (l < r) {
    // cout << nums[l].first << " " << nums[r].first << nline;

    if (nums[l].first + nums[r].first == target)
      { cout << nums[r].second << " " << nums[l].second; found = true; break; }
    
    if (nums[l].first + nums[r].first < target)
      { ++l; }
    else
      { --r; }
  }
  
  if (!found)
    { cout << "IMPOSSIBLE"; }
}