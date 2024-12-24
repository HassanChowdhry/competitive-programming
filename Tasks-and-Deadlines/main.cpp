#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fs first 
#define sc second 
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define rep(i,n) for(int i=0;i<n;++i)
#define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i]

void solve() {
  ll n; cin >> n;
  vector<pair<ll, ll>> intervals(n);
  rep(i, n) {
    ll duration, deadline; cin >> duration >> deadline;
    intervals[i].fs = duration; intervals[i].sc = deadline;
  }
  sort(intervals.begin(), intervals.end());

  ll time = 0, total = 0;
  rep(i, n) {
    time += intervals[i].fs;
    total += intervals[i].sc - time;
  }

  cout << total;
}

int main() {
  flash;
  solve();
  return 0;
}