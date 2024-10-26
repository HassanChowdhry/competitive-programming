#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int find(int p, vector<int> &parent) {
  if (p == parent[p])
    { return parent[p]; }
  
  parent[p] = find(parent[p], parent);
  return parent[p];
}

void unionn(int x, int y, vector<int> &parent, vector<int> &rank) {
  int px = find(x, parent), py = find(y, parent);

  if (px == py)
    { return; }

  if (rank[px] > rank[py])
    { parent[py] = px; rank[px] += rank[py]; }
  else
    { parent[px] = py; rank[py] += rank[px]; }
}

int main() {
  int n, m, x, y, px, py;
  char command;
  cin >> n >> m;
  vector<unordered_set<int>> adj(n+1);
  vector<unordered_set<int>> radj(n+1);
  vector<int> parent(n+1); vector<int> rank(n+1, 1);

  for (int i = 0; i < n+1; ++i)
    { parent[i] = i; }
  
  for (int i = 0; i < m; ++i) {
    
    cin >> command >> x >> y;

    if (command == 'f') { 
      adj[x].insert(y); radj[y].insert(x);
      unionn(x, y, parent, rank); continue; 
    }
    if (adj[x].count(y) || radj[x].count(y))
      { cout << x << " + " << y << "\n"; continue; }

    px = find(x, parent); py = find(y, parent);
    if (px == py)
      { cout << x << " - " << y << "\n"; continue; }
    else
      { cout << x << " ? " << y << "\n"; continue; }
  } 
}