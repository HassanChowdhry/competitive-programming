#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ump unordered_map
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ln "\n"

void solve() {
  int s1, s2, s3, s4; cin >> s1 >> s2 >> s3 >> s4;
  int a[] {s1, s2, s3, s4};
  sort(a, a + 4);
  s1 = a[0], s2 = a[1], s3 = a[2], s4 = a[3];
  int res = 0;
  if (s2 == s1) ++res;
  if (s2 == s3) ++res;
  if (s4 == s3) ++res;

  cout << res;
}

int main() {
  flash;
  solve();
  return 0;
}