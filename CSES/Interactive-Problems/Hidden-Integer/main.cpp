#include <bits/stdc++.h>
using namespace std;

void solve() {
  int l = 1, r = 1e9;
  int mid;

  while (l <= r) {

    int mid = (l + r) / 2;

    printf("? %d\n", mid);
    fflush(stdout);
    
    string response;
    cin >> response;

    if (response == "YES") {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  cout << "! " << l << "\n";
}

int main() {
  solve();
  return 0;
}