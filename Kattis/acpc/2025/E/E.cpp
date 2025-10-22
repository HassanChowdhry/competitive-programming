#include <bits/stdc++.h>
#define deb(x) cerr << #x << ": " << x << '\n'
#define debl(x) cerr << #x << ": " << x << ' '
#define fs first
#define sc second
using namespace std;
void LSH() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}



void solve() {
    int n; cin >> n; 
    map<string, int> mp;
    map<string, double> player_score; // event to mapping in vector
    map<string, map<int, int>> player_ranking;
    vector<vector<pair<double, string>>> board(9);
    int curr = 1;
    for (int i = 0; i < 8*n; ++i) {
        string name, event; double score; 
        cin >> name >> event >> score;
        int p=0;
        if (mp.count(event)) p = mp[event];
        else {
            p = curr; 
            mp[event] = curr;
            ++curr;
        }

        // cout << score << " " << name << " " << "\n";
        board[p].push_back({ score, name });
        // cout << event << " " << p << " " << score << " " << name << " " << board[p][0].fs << " " << board[p][0].sc << "\n";
    }

    // EVENT -> [score, name]

    for (int i = 1; i < 9; ++i) {
        sort(board[i].rbegin(), board[i].rend());

        for (int j = 0; j < board[i].size(); ++j) {
            // cout << board[i][j].fs << " " << board[i][j].sc << "\n";
            auto [e_score, name] = board[i][j];
            // cout << e_score << " " << name << " " << "\n";

            int ok = 1;
            double score = (double)j + 1.0;
            int z = j;
            while (z + 1 < n && board[i][z].fs == board[i][z + 1].fs) {
                ++z;
                ok = 0;
                score += ((double)z + 1.0);
            }
            if (ok) {
                player_score[name] += (double)score;
                player_ranking[name][j + 1] += 1;
                // cout << name << " " << player_score[name] << " " << "\n";
            } else {
                // cout << score << " " << z - j + 1 << "\n";
                score /= ((double)z - (double)j + 1.0);
                // cout << score << "\n";
            }

            for (int k = j; !ok && k <= z; ++k) {
                // cout << board[i][k].sc << "\n";
                player_score[board[i][k].sc] += (double)score;
                player_ranking[board[i][k].sc][j + 1] += 1;
            }
            j = z;
        }
    } 

    double mn = 1e9;
    int cnt = 0;
    string name = "";
    vector<string> a;
    for (auto it : player_score) {
        if (mn > it.sc) {
            mn = it.sc;
            cnt = 1;
            name = it.fs;
            a.clear();
            a.push_back(it.fs);
        } else if (mn == it.sc) {
            name = "tie";
            ++cnt;
            a.push_back(it.fs);
        }
    }
    if (cnt == 1) {
        cout << name << " " << fixed << setprecision(1) << mn; return;
    }

    for (int i = 1; i <= 3; ++i) {
        int mx = -1;
        int cnti = 0;
        string namei = "";
        vector<string> b;
        for (string it : a) {
            int cc = player_ranking[it][i];
            // cout << it << " " << i << " " << player_ranking[it][i] << "\n";
            if (mx < cc) {
                mx = cc;
                cnti = 1;
                namei = it;
                b.clear();
                b.push_back(it);
            } else if (mx == cc) {
                namei = "tie";
                ++cnti;
                b.push_back(it);
            }
            a = b;
        }
        if (cnti == 1) {
            cout << namei << " " << fixed << setprecision(1)<< mn; return;
        }
    }
    cout << "tie" << " " << fixed << setprecision(1) << mn;
}
int main() {
    LSH();
    solve();
}