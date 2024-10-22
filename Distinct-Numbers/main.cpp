#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, num; cin >> n; set<int> set;

  for (int i = 0; i < n; ++i) 
    { cin >> num; set.insert(num); }

  cout << set.size();
}