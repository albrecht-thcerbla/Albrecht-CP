#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int n, x[101];
bool used[10];

void backtrack(int i) {
  for (int j = 1; j <= n; j++) {
    if (!used[j] && abs(j - x[i - 1]) != 1) {
      x[i] = j;
      used[j] = 1;
      if (i == n) {
        for (int c = 1; c <= n; c++) {
          cout << x[c];
        }
        cout << '\n';
      }
      else backtrack(i + 1);
      used[j] = 0;
    }
  }
}
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  x[0] = -1;
  backtrack(1);  
  return 0;
}