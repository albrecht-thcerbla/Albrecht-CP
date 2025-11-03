#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int n, a[202], x[202];

void backtrack(int i, int st) {
  for (int j = st; j <= n; j++) {
    if (a[j] > x[i - 1]) {
      x[i] = a[j];
      if (i >= 2) {
        for (int c = 1; c <= i; c++) {
          cout << x[c] << " ";
        }
        cout << '\n';
      }
      backtrack(i + 1, j + 1);
    }
  
  }
}
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  backtrack(1, 1);
  return 0;
}