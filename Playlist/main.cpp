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
  int n, num; cin >> n;
  vector<int> nums(n); set<int> cnt;
  loop(n)
    { cin>>num; nums[i]=num; }
  
  int l = 0, r = 0, res = 0;
  while (r < n) {
    while (l < r && cnt.count(nums[r]))
      { cnt.erase(nums[l]); ++l; }
 
    cnt.insert(nums[r]);
    res = max(res, r - l + 1);
    ++r;
  }
  cout << res;
}