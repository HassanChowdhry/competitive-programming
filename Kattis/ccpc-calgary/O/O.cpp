#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n;
    int t1 = 0, t2 = 0;
    int ok1 = 1, ok2 = 1;
    int a1 = 0, a2 = 0;
    string c;
    for (int i = 0; i < n; ++i) {
      cin >> c;
      
      if (c == "J" || c == "Q" || c == "K") {
        t1 += 10;
      } else if (c == "A") {
        ++a1;
      } else {
        t1 += stoi(c);
      }

      if (t1 > 21) {
        ok1 = 0;
      }
    }

    if (a1 == 3) {
      t1 = 13;
    } else if (a1 == 2) {
      if (t1 + 12 <= 21) {
        t1 += 12;
      } else {
        t1 += 2;
      }
    } else if (a1 == 1) {
      if (t1 + 11 <= 21) {
        t1 += 11;
      } else {
        ++t1;
      }
    }
    
    cin >> m;
    for (int i = 0; i < m; ++i) {
      cin >> c;
      if (c == "J" || c == "Q" || c == "K") {
        t2 += 10;
      } else if (c == "A") {
        ++a2;
      } else {
        t2 += stoi(c);
      }

      if (t2 > 21) {
        ok2 = 0;
      }
    }

    if (a2 == 3) {
      t2 = 13;
    } else if (a2 == 2) {
      if (t2 + 12 <= 21) {
        t2 += 12;
      } else {
        t2 += 2;
      }
    } else if (a2 == 1) {
      if (t2 + 11 <= 21) {
        t2 += 11;
      } else {
        ++t2;
      }
    }
    

    // cout << t1 << " " << t2 << "\n";
    if (ok1 == ok2) {
      if (ok1 == 0) {
        cout << "Push";
      } else if (t1 == t2) {
        cout << "Push";
      } else if (t1 < t2) {
        cout << "Player";
      } else {
        cout << "Dealer";
      }
    } else if (ok1 == 1) {
      cout << "Dealer";
    } else {
      cout << "Player";
    }
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}