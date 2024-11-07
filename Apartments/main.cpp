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
using namespace std;

int main() {
  int n, m, k; ll mid, left, right; cin >> n >> m >> k;
  vector<pair<ll, ll>> intervals(n); vector<ll> apartments(m);
  
  loop(n) {
    cin >> mid; left = mid - k; right = mid + k;
    intervals[i] = {left, right};
  } sort(intervals.begin(), intervals.end());

  loop(m) 
    { cin >> apartments[i]; } sort(apartments.begin(), apartments.end());
  
  int j = 0, res = 0;
  
  loop(m) {
    mid = apartments[i];
    while (j < n && mid > intervals[j].second) { ++j; }
    
    if ((j < n && mid < intervals[j].first)) { continue; }
    
    if (j >= n) { break; }
    
    ++res; ++j;
  }

  cout << res;
}