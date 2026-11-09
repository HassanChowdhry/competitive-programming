#include <bits/stdc++.h>
using namespace std;
vector<int> g1[10000005], g2[10000005];
stack<int> st;
vector<int> mark1, mark2;
int d1, d2;
// string s;

void process(const string& s, vector<int> (&g)[10000005], vector<int>& mark) {
    string num = "";
    int prev = -1; // 0 -> space, number, ), (;
    for (char c : s) {
        if (c >= '0' && c <= '9') {
            num += c;
            prev = 1;
        } else if (c == '(') {
            if (num != "" && prev == 1) {
                int n = stoi(num);
                if (!st.empty()) {
                    g[st.top()].push_back(n);
                }
                st.push(n);
                mark.push_back(n);
            }
            num = "";
            prev = 2;
        } else if (c == ')') {
            if (num != "" && prev == 1) {
                int n = stoi(num);
                if (!st.empty()) {
                    g[st.top()].push_back(n);
                }
                st.push(n);
                mark.push_back(n);
            }
            num = "";
            if (!st.empty()) st.pop();
            prev = 2;
        } else if (c == ' ') {
            if (num != "" && prev == 1) {
                int n = stoi(num);
                if (!st.empty()) {
                    g[st.top()].push_back(n);
                }
                st.push(n);
                mark.push_back(n);
            }
            num = "";
            prev = 0;
        }
    }

    if (num != "") {
        int n = stoi(num);
        if (!st.empty()) {
            g[st.top()].push_back(n);
        }
        st.push(n);
        mark.push_back(n);
    }
}

int bfs(int d) {
    queue<int> q;
    q.push(d); 

    while (!q.empty()) {
        int n = q.size();
        for (int j = 1; j <= n; ++j) {
            int u = q.front(); q.pop();

            if (g1[u].size() != g2[u].size()) return 0;

            int m = g1[u].size();
            for (int i = 0; i < m; ++i) {
                if (g1[u][i] != g2[u][i]) return 0;
            }

            for (int v: g1[u]) {
                q.push(v);
            }

        }
    }

    return 1;
}

void solve() {
    string s;
    getline(cin, s);
    process(s, g1, mark1);

    while(!st.empty()) st.pop();
    
    getline(cin, s);
    process(s, g2, mark2);

    int n = mark1.size(), m = mark2.size();
    if (n != m) {
        cout << "No";
        return;
    }

    if (n == 0 && m == 0) {
        cout << "Yes";
        return;
    }
    
    d1 = mark1[0], d2 = mark2[0];
    sort(mark1.begin(), mark1.end());
    sort(mark2.begin(), mark2.end());
    if (d1 != d2) {
        cout << "No";
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (mark1[i] != mark2[i]) {
            cout << "No";
            return;
        }
    }

    for (int u : mark1) {
        sort(g1[u].begin(), g1[u].end());
    }

    for (int u : mark2) {
        sort(g2[u].begin(), g2[u].end());
    }

    int ok = bfs(d1);

    if (ok) cout << "Yes";
    else cout << "No";
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    solve();
    return 0;
}