#include <bits/stdc++.h>
#define MOD 1000000007
#define ln "\n"
#define ll long long
using namespace std;

double getClockScore(string clock) {
  int hours = stoi(clock.substr(0, 2)) % 12;
  int minutes = stoi(clock.substr(3, 2));
  
  int pos = hours * 60 + minutes;
  int res = (pos <= 180 ? pos: (720 - pos));
  // cout << pos << " " << res << ln;

  double ratio = ((double) res / 180.0);
  return 1.0 - ratio;
}

int main() {
  int tests; cin >> tests;
  string name, clock; double h, w, cs; ll score;
  int best = -1;
  string who = "";
  bool tie = false;

  for (int i = 0; i < tests; ++i) {
    cin >> name >> h >> w >> clock;
    cs = getClockScore(clock);
    score = (ll)floor((((5.0 * h) + w) * cs) + 1e-12);

    if (score > best) {
        best = score;
        who = name;
        tie = false;                 
    } else if (score == best && name != who) {
        tie = true;                  
    }
  }

  cout << (tie ? "tie" : who) << " " << best << "\n";    // cout << cs << "\n";
    // cout << score << "\n";
}