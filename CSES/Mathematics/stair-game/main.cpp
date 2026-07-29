#include <bits/stdc++.h>
using namespace std;

int n;

void solve() {
	cin >> n;
  long long sum = 0;
  vector<long long> p(n + 1);

  // there are various explanations online
  // odd steps (in a 1-idx based array) do not matter
  // this has to do with cancelling out
  // Player A: moves odd to even, B can move even back to odd
  // Vice versa is not guaranteed as if A can move an even to odd ->
  // B is NOT GUARANTEED to be able to move back to an even state
  // this is thanks to 1 being a terminal state
  // conclusion: odd steps are not included in the NIM game
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
  }


  for (int i = 2; i <= n; i+=2) {
    sum ^= p[i];
  }

  cout << (sum != 0 ? "first" : "second") << "\n";
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int t; cin >> t;
  while (t--) solve();
	return 0;
}