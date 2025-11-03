#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -2, 1};

int n, s, t, u, v;
int a[101][101];

void loang(int i, int j) {
  a[i][j] = 0;
  for (int k = 0; k < 8; k++) {
    int i1 = i + dx[k];
    int j1 = j + dy[k];
    if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < n && a[i1][j1]) loang(i1, j1);
  }
}
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> s >> t >> u >> v;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }  
  loang(s - 1, t - 1);
  if (!a[u - 1][v - 1]) cout << "YES" << '\n';
  else cout << "NO" << '\n';
  return 0;
}