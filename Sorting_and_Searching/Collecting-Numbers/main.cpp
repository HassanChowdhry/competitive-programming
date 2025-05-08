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
  int n; cin >> n;
  vector<int> nums(n); input(nums, n);
  unordered_set<int> collected; ll count = 0;

  loop(n) {
    if (!collected.count(nums[i]-1))
      { ++count; }
    collected.insert(nums[i]);
  }

  cout << count;
}