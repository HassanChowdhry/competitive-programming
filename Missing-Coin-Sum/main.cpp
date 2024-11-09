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
  ll sum = 0; bool found = false;
  vector<int> nums(n); input(nums, n);
  sort(nums.begin(), nums.end());

  loop(n) {
    if ((sum + 1) < nums[i]) 
      { cout << sum+1; found = true; break; }
    
    sum += nums[i];
  }

  if (!found) 
    { cout << sum+1; }
}