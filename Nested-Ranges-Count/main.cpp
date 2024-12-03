#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define flash ios_base::sync_with_stdio(false);cin.tie(NULL);
#define loop(n) for(int i=0;i<n;++i)
#define loopx(x, n) for(int i=x;i<n;++i)
#define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i];
#define ln "\n";
struct Interval {
  int start;
  int end;
  int index;

  bool operator<(const Interval &other) const {
    if (start != other.start) {
      return start < other.start;
    }
    if (end != other.end) {
      return end > other.end;
    }
    return index < other.index;
  }
};

void solve() {
  int n, s, e; cin >> n;
  vector<Interval> intervals(n); 
  vector<int> contains(n, 0), contained(n, 0);
  loop(n) 
    { cin >> s >> e; intervals[i].start = s; intervals[i].end = e; intervals[i].index = i; }
  sort(intervals.begin(), intervals.end());

  ordered_set<pair<int, int>> ost, ost_l;
  int order;
  loop(n) {
    ost.insert({ intervals[i].end, i });
    order = ost.size() - ost.order_of_key({ intervals[i].end, 0 }) - 1;
    contained[intervals[i].index] = order;
  }

  int l = 0;
  for (int i = n-1; i >= 0; --i) {
    ost_l.insert({ intervals[i].end, l++ });
    order = ost_l.order_of_key({ intervals[i].end, ost_l.size() }) - 1;
    contains[intervals[i].index] = order;
  } 

  loop(n) { cout << contains[i] << " "; } cout << ln;
  loop(n) { cout << contained[i] << " "; } cout << ln;
}

int main() {
  flash
  solve();
  return 0;
}