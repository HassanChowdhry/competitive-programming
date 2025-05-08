#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

float getClockScore(string clock) {
  int hours = stoi(clock.substr(0, 2));
  int minutes = stoi(clock.substr(3, 2));
  float ratio = (1.0 / 180.0);

  if (hours == 12 && minutes == 0)
    { return 1.0; }
  if ((hours == 3 || hours == 9) && minutes == 0)
    { return 0.0; }
  
  if (hours < 12 && hours >= 9)
    { hours -= 9; }
  else {
    if (hours == 12) hours = 0;
    hours = 2 - hours;
    minutes = 60 - minutes;
    minutes = minutes % 60;
  }

  minutes += (hours * 60);

  return ratio * (float) minutes;
}

int main() {
  int tests; cin >> tests;
  string name, clock; float h, w, cs; int score;
  int maxscore = 0; string maxname = "";

  for (int i = 0; i < tests; ++i) {
    cin >> name >> h >> w >> clock;
    cs = getClockScore(clock);
    score = floor(((5.0 * h) + w) * cs);

    if (maxscore == score && maxname != name)
      { maxname = "tie"; }
    if (maxscore < score)
      { maxscore = score; maxname = name; }
  }

    cout << maxname << " " << maxscore << "\n";
    // cout << cs << "\n";
    // cout << score << "\n";
}