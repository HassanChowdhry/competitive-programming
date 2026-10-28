#include <bits/stdc++.h>
using namespace std;

int n, r;
int a[500005];

void solve() {
  cin >> n >> r;
  
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  sort(a+1, a+n+1);

  // at most 40 * R, then we will never bomb them more than x times
  // now how do we know which point will have the most hits.
  // do I need to go through all points in the line ? 
  // check x - R
}

int main() {
  cout.tie(0); cin.tie(0); ios_base::sync_with_stdio(0);
  solve();
}