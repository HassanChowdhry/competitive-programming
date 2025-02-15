#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fs first
#define sc second
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define rep(i,n) for(int i=0;i<n;++i)
#define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i]
#define ln "\n"
struct Interval {
  ll start;
  ll end;
  ll weight;

  bool operator<(const Interval &other) const {
    // sort by end then start then weight
    if (end != other.end) return end < other.end;
    if (start != other.start) return start < other.start;
    return weight < other.weight;
  }
};

int binsearch(int i, vector<Interval>& intervals) {
  int j = -1;
  int mid, l = 0, r = i-1;
  while (l <= r) {
    mid = (l + r) / 2;
    if (intervals[mid].end < intervals[i].start)
      { j = mid; l = mid + 1; }
    else
      { r = mid - 1; }
  }

  return j;
}

void solve() {
  int n; cin >> n;
  vector<Interval> intervals(n);
  vector<ll> dp(n, 0);
  rep(i, n) 
    { cin >> intervals[i].start >> intervals[i].end >> intervals[i].weight; }

  sort(intervals.begin(), intervals.end());

  // for each do binsearch then put it dp[i] = max(dp[pred] + wi, dp[i-1]);
  dp[0] = intervals[0].weight;
  for (int i = 1; i < n; ++i) {
    int pred = binsearch(i, intervals);
    if (pred == -1)
      { dp[i] = max(intervals[i].weight, dp[i-1]); } 
    else
      { dp[i] = max(dp[pred] + intervals[i].weight, dp[i-1]); }
  }

  cout << dp[n-1];
}

int main() {
  flash;
  solve();
  return 0;
}