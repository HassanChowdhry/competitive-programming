#include <bits/stdc++.h>
# define ll long long
# define pb push_back
# define fs first 
# define sc second 
# define all(a) a.begin(),a.end()
# define flash ios_base::sync_with_stdio(false);cin.tie(NULL);
# define test int t;cin>>t;while(t--)
# define loop(n) for(int i=0;i<n;++i)
# define loopx(x, n) for(int i=x;i<n;++i)
# define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i];
# define nline "\n"
using namespace std;
int MOD=1000000007;

struct Interval {
  int start;
  int end;
  int index;

  bool operator<(const Interval &other) const {
    if (start != other.start) { return start < other.start; }
    if (end != other.end) { return end < other.end; }
    return index < other.index;
  }
};

struct Room {
  int end;
  int index;
  int room;

  bool operator<(const Room &other) const {
    if (end != other.end) { return end > other.end; }
    if (index != other.index) { return index > other.index; }
    return room > other.room;
  }
};

void solve() {
  int n, res = 0; cin >> n;
  priority_queue<Room> minheap;
  priority_queue<int, vector<int>, greater<int>> rooms;
  vector<Interval> intervals(n); vector<int> roomUsed(n);
  
  loop(n) { cin >> intervals[i].start >> intervals[i].end; intervals[i].index = i; }
  sort(intervals.begin(), intervals.end());

  loop(n) {
    // if (!minheap.empty()) {
    //   cout << minheap.top().end << " " << minheap.top().index << " " << minheap.top().room << nline;
    // }
    while (!minheap.empty() && minheap.top().end < intervals[i].start) { 
      rooms.push(minheap.top().room);
      minheap.pop();
    }

    if (rooms.empty()) {
      ++res;
      roomUsed[intervals[i].index] = res;
      minheap.push({intervals[i].end, intervals[i].index, res});
    } else {
      roomUsed[intervals[i].index] = rooms.top();
      minheap.push({intervals[i].end, intervals[i].index, rooms.top()});
      rooms.pop();
    }
  }

  cout << res << nline;
  loop(n) { cout << roomUsed[i] << " "; }
}

int main() {
  flash
  solve();
  return 0;
}