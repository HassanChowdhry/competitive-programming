#include <bits/stdc++.h>
using namespace std;

void LSH() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

unordered_set<string> ch;
vector<int> frq('z' + 1, 0);
string s;
int check(string &w1, string &w2, string &w3) {
    for (int i = 0; i < 3; ++i) {
        s = w1[i];
        s += w2[i];
        s += w3[i];
        if (!ch.count(s)) return 0;
    }

    // cout << w1 << " " << w1[0] << "\n";
    // cerr << w1.size() << " " << w2.size() <<" " << w3.size()<<'\n';
    s = "";
    s += w1[0];
    s += w2[1];
    s += w3[2];
    if (!ch.count(s)) return 0;
    s = "";
    s += w1[2];
    s += w2[1];
    s += w3[0];
    if (!ch.count(s)) return 0;

    return 1;
}

void test() {
    cout << 500 << "\n";
    int pos = 0;
    string tmp = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < 500; ++i) {
        string s;
        for(int j = 0; j<3; ++j){
            s += tmp[pos];
            pos+=3; pos%=26;
        }
        cout << s << "\n";
    }
}

void solve() {
    int n; cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
        ch.insert(words[i]);
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ++frq[words[i][0]]; ++frq[words[i][1]]; ++frq[words[i][2]];
        if (frq[words[i][0]] > 1 || frq[words[i][1]] > 1 || frq[words[i][2]] > 1) {
            --frq[words[i][0]]; --frq[words[i][1]]; --frq[words[i][2]];
            continue;
        }
        for (int j = 0; j < n; ++j) {
            if (j == i) continue;
            ++frq[words[j][0]]; ++frq[words[j][1]]; ++frq[words[j][2]];
            if (frq[words[j][0]] > 1 || frq[words[j][1]] > 1 || frq[words[j][2]] > 1) {
                --frq[words[j][0]]; --frq[words[j][1]]; --frq[words[j][2]];
                continue;
            }
            for (int k = 0; k < n; ++k) {
                if (k == j || i == k) continue;
                ++frq[words[k][0]]; ++frq[words[k][1]]; ++frq[words[k][2]];
                if (frq[words[k][0]] > 1 || frq[words[k][1]] > 1 || frq[words[k][2]] > 1) {
                    --frq[words[k][0]]; --frq[words[k][1]]; --frq[words[k][2]];
                    continue;
                }
                int ok = check(words[i], words[j], words[k]);
                // ok += check(words[i], words[k], words[j]);
                // ok += check(words[j], words[i], words[k]);
                // ok += check(words[j], words[k], words[i]);
                // ok += check(words[k], words[j], words[i]);
                // ok += check(words[k], words[i], words[j]);
                ans+=ok;
                --frq[words[k][0]]; --frq[words[k][1]]; --frq[words[k][2]];
            }
            --frq[words[j][0]]; --frq[words[j][1]]; --frq[words[j][2]];
        }
        --frq[words[i][0]]; --frq[words[i][1]]; --frq[words[i][2]];
    }
    cout << ans;
}

int main() {
    LSH();
    // test();
    solve();
}