# include <bits/stdc++.h>
# define ll long long
# define pb push_back
# define all(a) a.begin(),a.end()
# define flash ios_base::sync_with_stdio(false);cin.tie(NULL);
# define test int t;cin>>t;while(t--)
# define loop(n) for(int i=0;i<n;++i)
# define loopx(x, n) for(int i=x;i<n;++i)
# define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i];
# define nline "\n"
using namespace std;
int MOD=1000000007;

int main() {
  int n, s, e, res = 0; cin >> n;
  vector<pair<int, int>> intervals(n); 

  loop (n) { cin >> s >> e; intervals[i] = { s, e }; }
  sort(intervals.begin(), intervals.end());
  int end = intervals[0].second;
  
  // loop(n) {
  //   cout << intervals[i].first << " " << intervals[i].second << nline;
  // }

  loopx(1, n) {
    if (end <= intervals[i].first) 
      { end = intervals[i].second; ++res; continue; }
    
    if (end > intervals[i].second) 
      { end = intervals[i].second; }
  }
  
  cout << ++res;
}