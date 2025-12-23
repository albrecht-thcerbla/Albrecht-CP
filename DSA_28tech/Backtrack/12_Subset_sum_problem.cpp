#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int n, a[101], x[101], s, ok;

void backtrack(int i, int st, int sum) {
  if (ok) return;
  for (int j = st; j <= n; j++) {
    if (sum + a[j] <= (s >> 1)) {
      x[i] = a[j];
      if (sum + a[j] == (s >> 1)) ok = 1;
      else backtrack(i + 1, j + 1, sum + a[j]);
    }
  }
}
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i], s += a[i];
  if (s & 1) return cout << -1, 0;
  sort(a + 1, a + n + 1);
  backtrack(1, 1, 0);  
  cout << ok << '\n';
  return 0;
}