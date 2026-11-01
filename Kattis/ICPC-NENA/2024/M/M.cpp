#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>

string s, p;
int t, n, ok, cl, m;
char opp[260];

ii pos[500];
ii poss[500];
vector<string> kb = {
  "`1234567890-=",
  "qwertyuiop[]\\",
  "asdfghjkl;\'",
  "zxcvbnm,./",
};

vector<string> kbs = {
  "~!@#$%^&*()_+",
  "QWERTYUIOP{}|",
  "ASDFGHJKL:\"",
  "ZXCVBNM<>?",
};

string ls = "`123456qwertasdfgzxcvb";
string lss = "~!@#$%^QWERTASDFGZXCVB";
string rs = "7890-=yuiop[]\\hjkl;'nm,./";
string rss = "&*()_+YUIOP{}|HJKL:\"NM<>?";


int isal(char c) {
  return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int instr(string a, char c) {
  return (find(a.begin(), a.end(), c) != a.end());
}

int check_emc(string s1, string s2) {
  // s1 > s2
  // cout << " : " << s1 << " " << s2 << "\n";
  int e = 1, e2 = 1;
  for (int i = 0, j = 0; i < s2.size();) {
    // cout << s1[j] << " " << s2[i] << "\n";
    if (s2[i] != s1[j]) {
      if (e == 2) {
        e = 0;
        break;
      }
      e = 2;
      ++j; continue;
    }
    ++i; ++j;
  }

  if (e) return 1;

  for (int i = 0, j = 0; i < s2.size();) {
    if (isal(s1[j]) && isal(s2[i])) {
      if (s1[j] != opp[s2[i]]) {
        if (e2 == 2) {
          e2 = 0; break;
        }
        e2 = 2;
        ++j; continue;
      }
    } else if (s2[i] != s1[j]) {
      if (e2 == 2) {
        e2 = 0; break;
      }
      e2 = 2;
      ++j; continue;
    }
    ++i; ++j;
  }
  
  return e || e2;
}

int check() {
  int okk = 1, okkk = 1;
  for (int i = 0; i < n; ++i) {
    if (s[i] != p[i]) {
      okk = 0; break;
    }
  }

  if (okk) return 1;

  for (int i = 0; i < n; ++i) {
    if (isal(s[i]) && isal(p[i])) {
      if (s[i] == opp[p[i]]) continue;
      okkk = 0; break;
    } else if (s[i] != p[i]) {
      okkk = 0; break;
    }
  }

  return okkk;
}

int check_ls() {
  // case 1 no caps
  int ok1 = 1, ok2 = 1;
  for (int i = 0; i < n; ++i) {
    // cout << ls << " " << s[i]
    if (instr(ls, s[i])) {
      // cout << s[i] << " ls \n";
      auto[r, c] = pos[s[i]];
      if (p[i] != kb[r][c+1]) {
        ok1 = 0; break;
      }
    } else if (instr(lss, s[i])) {
      // cout << s[i] << " lss \n";
      auto[r, c] = pos[s[i]];
      if (p[i] != kbs[r][c+1]) {
        ok1 = 0; break;
      }
    } else if (s[i] != p[i]) {
      // cout << s[i] << " r \n";
      ok1 = 0; break;
    }
  }

  // return ok1;
  // cout << ok1 << " ";
  if (ok1) return 1;
  // case 2 no caps
  for (int i = 0; i < n; ++i) {
    if (instr(ls, s[i])) {
      auto[r, c] = pos[s[i]];
      if (isal(kbs[r][c+1])) {
        if (p[i] != kbs[r][c+1]) {
          ok2 = 0; break;
        }
      } else if (p[i] != kb[r][c+1]) {
        ok2 = 0; break;
      }
    } else if (instr(lss, s[i])) {
      auto[r, c] = pos[s[i]];
      if (isal(kb[r][c+1])) {
        // cout << "meow\n";
        if (p[i] != kb[r][c+1]) {
          ok2 = 0; break;
        }
      } else if (p[i] != kbs[r][c+1]) {
        ok2 = 0; break;
      }
    } else {
      if (isal(s[i]) && isal(p[i])) {
        if (s[i] == opp[p[i]]) continue;
        ok2 = 0; break;
      } else if (s[i] != p[i]) {
        ok2 = 0; break;
      }
    }
  }
  // cout << ok2 << "\n";
  return ok2;
}

int check_rs() {
  // case 1 no caps
  int ok1 = 1, ok2 = 1;
  for (int i = 0; i < n; ++i) {
    if (instr(rs, s[i])) {
      auto[r, c] = pos[s[i]];
      
      if (p[i] != kb[r][c-1]) {
        ok1 = 0; break;
      }
    } else if (instr(rss, s[i])) {
      auto[r, c] = pos[s[i]];
      if (p[i] != kbs[r][c-1]) {
        ok1 = 0; break;
      }
    } else if (s[i] != p[i]) {
      ok1 = 0; break;
    }
  }

  // cout << "rs " << ok1 << "\n";
  // return ok1;
  if (ok1) return 1;
  // case 2 caps
  for (int i = 0; i < n; ++i) {
    if (instr(rs, s[i])) {
      auto[r, c] = pos[s[i]];
      // cout << s[i] << " " << p[i] << " " << kbs[r][c-1] << "\n";
      // cout << s[i] << " " << p[i] << " " << kb[r][c-1] << "\n";
      if (isal(kbs[r][c-1])) {
        if (p[i] != kbs[r][c-1]) {
          ok2 = 0; break;
        }
      } else if (p[i] != kb[r][c-1]) {
        ok2 = 0; break;
      }
    } else if (instr(rss, s[i])) {
      auto[r, c] = pos[s[i]];
      // cout << s[i] << " " << p[i] << " " << kbs[r][c-1] << "\n";
      // cout << s[i] << " " << p[i] << " " << kb[r][c-1] << "\n\n";
      if (isal(kb[r][c-1])) {
        // cout << "meow\n";
        if (p[i] != kb[r][c-1]) {
          ok2 = 0; break;
        }
      } else if (p[i] != kbs[r][c-1]) {
        ok2 = 0; break;
      }
    } else {
      if (isal(s[i]) && isal(p[i])) {
        if (s[i] == opp[p[i]]) continue;
        ok2 = 0; break;
      } else if (s[i] != p[i]) {
        ok2 = 0; break;
      }
    }
  }
  // cout << "rsss " << ok2 << "\n";
  return ok2;
}

void solve() {
  int ok1;
  // caps can happen in conjuction with any of the other
  cin >> s >> t;
  n = s.size();

  for (char c = 'A'; c <= 'Z'; ++c) {
    char o = c - 'A' + 'a';
    opp[c] = o; opp[o] = c;
  }

  for (int i = 0; i < kb.size(); ++i) {
    for (int j = 0; j < kb[i].size(); ++j) {
      pos[kb[i][j]] = {i, j};
      pos[kbs[i][j]] = {i, j};
    }
  }

  for (int i = 1; i <= t; ++i) {
    cin >> p;
    ok = cl = ok1 = 0;
    m = p.size();

    if (m == n - 1 || m == n + 1) {
      string s1 = s, s2 = p;
      if (n < m) swap(s1, s2);
      ok = check_emc(s1, s2);
      if (!ok) { cout << "NO\n"; continue; }
    } else if (m == n) {
      if (check()) {
        cout << "YES\n"; continue;
      }
      ok = check_ls();
      ok1 = check_rs();
      // cout << ok << " " << ok1 << "\n";
      if (!(ok ^ ok1)) { cout << "NO\n"; continue; }
    } else {
      cout << "NO\n"; continue;
    }

    cout << "YES\n";
  }
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}
