#include <bits/stdc++.h>
using namespace std;

string s; char c;
vector<int> d;

int valid() {
  int hyp = 0;
  int l_hyp = -1;
  int checksum = 0;
  int curr_checksum = 0;
  int curr = 10;
  int n = s.size();
  // cout << "HELLO\n";
  for (int i = 0; i < n; ++i) {
    c = s[i];
    if (c == '-') {
      if (l_hyp == i-1 || i == n - 1) return 0;
      ++hyp;
      l_hyp = i;
      continue;
    }

    if (c == 'X' && i != n - 1) {
      return 0;
    }

    if (c == 'X' && i == n - 1) {
      curr_checksum = 10;
    } else if (i == n - 1) {
      curr_checksum = c-'0';
    } else if (c != '-') {
      // cout << c << " ";
      checksum += (curr * (c-'0')); --curr;
      d.push_back(c-'0');
    } else {
      return 0;
    }
  }

  checksum += curr_checksum;
  checksum %= 11;

  // cout << "HELLO\n";
  if (hyp == 3) {
    int ok2 = s[n - 2] == '-';
    if (!ok2) return 0;
  }

  // cout << checksum << " " << curr_checksum << "\n";

  return hyp <= 3 && checksum == 0;
}

void solve() {
  cin >> s;
  d.clear();
  d.push_back(9); d.push_back(7); d.push_back(8);
  int ok = valid();
  // cout << d.size() << "\n";
  if (!ok || d.size() != 12) {
    cout << "invalid\n";
    return;
  }

  cout << "978-";
  for (int i = 0; i < s.size() - 1; ++i) {
    cout << s[i];
  }

  int checksum = 0;
  int m = d.size();
  for (int i = 0; i < m; ++i) {
    if (i % 2 == 0) {
      checksum += (d[i]);
    } else {
      checksum += (d[i] * 3);
    }
  }
  checksum %= 10;
  cout << (10-checksum) % 10;
  cout << "\n";
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int t; cin >> t;
  while(t--) solve();
  return 0;
}