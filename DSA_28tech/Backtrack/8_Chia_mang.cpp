#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int n, k, sum;
int a[101], x[101];
bool used[101], ok;

void backtrack(int i, int st, int ssum, int cnt) {
  if (k == cnt - 1) {
    ok = 1;
    return;
  }
  for (int j = st; j <= n; j++) {
    if (!used[j] && ssum + a[j] <= sum) {
      used[j] = 1;
      x[i] = a[j];
      if (ssum + a[j] == sum) backtrack(i + 1, 1, 0, cnt + 1);
      else backtrack(i + 1, j + 1, ssum + a[j], cnt);
      used[j] = 0;
    }
  }
}
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
  if (sum % k == 0) {
    sum /= k;
    backtrack(1, 1, 0, 1);
    cout << ok << '\n';
  } else return cout << 0, 0;
    
  return 0;
}