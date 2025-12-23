#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, m; cin >> n >> m;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  sort(all(a)); sort(all(b));
  int i = 0, j = 0;
  while (i < n && j < m) {
    if (a[i] < b[j]) {
      cout << a[i] << " ";
      i++;
    } else {
      cout << b[j] << " ";
      j++;
    }
  }
  while (i < n) cout << a[i++] << " ";
  while (j < m) cout << b[j++] << " ";
  return 0;
}