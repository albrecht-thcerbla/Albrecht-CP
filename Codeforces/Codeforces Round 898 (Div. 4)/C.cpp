#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

int a[11][11];
char c[11][11];

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= 10; j++) {
      if (i == 1 && j <= 10) a[i][j] = 1;
      if (j <= 10 && i == 10) a[i][j] = 1;
      if (j == 1 && i <= 10) a[i][j] = 1;
      if (j == 10 && i <= 10) a[i][j] = 1;
      
      if (i == 2 && j >= 2 && j <= 9) a[i][j] = 2;
      if (i == 9 && j >= 2 && j <= 9) a[i][j] = 2;
      if (j == 2 && i >= 2 && i <= 9) a[i][j] = 2;
      if (j == 9 && i >= 2 && i <= 9) a[i][j] = 2;

      if (i == 3 && j >= 3 && j <= 8) a[i][j] = 3;
      if (i == 8 && j >= 3 && j <= 8) a[i][j] = 3;
      if (j == 3 && i >= 3 && i <= 8) a[i][j] = 3;
      if (j == 8 && i >= 3 && i <= 8) a[i][j] = 3;

      if (i == 4 && j >= 4 && j <= 7) a[i][j] = 4;
      if (i == 7 && j >= 4 && j <= 7) a[i][j] = 4;
      if (j == 4 && i >= 4 && i <= 7) a[i][j] = 4;
      if (j == 7 && i >= 4 && i <= 7) a[i][j] = 4;

      if (i == 5 && j >= 5 && j <= 6) a[i][j] = 5;
      if (i == 6 && j >= 5 && j <= 6) a[i][j] = 5;
      if (j == 5 && i >= 5 && i <= 6) a[i][j] = 5;
      if (j == 6 && i >= 5 && i <= 6) a[i][j] = 5;
    }
  }    
  int tt; cin >> tt;
  while (tt--) {
    for (int i = 1; i <= 10; i++) {
      for (int j = 1; j <= 10; j++) {
        cin >> c[i][j];
      }
    }
    int sum = 0;
    for (int i = 1; i <= 10; i++) {
      for (int j = 1; j <= 10; j++) {
        if (c[i][j] == 'X') sum += a[i][j];
      }
    }
    cout << sum << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

