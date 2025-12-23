#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int n, k, s, x[505], cnt;

void backtrack(int i, int st, int sum) {
  for (int j = st; j <= n; j++) {
    x[i] = j;
    if (i == k) {
      if (sum + j == s) ++cnt;
    }
    else backtrack(i + 1, j + 1, sum + j);
  }
}
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> k >> s;
  backtrack(1, 1, 0);
  cout << cnt << '\n';
  return 0;
}
