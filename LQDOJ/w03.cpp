#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) a[i] = i;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << a[j] + i << " ";
    }
    cout << '\n';
  }
  return 0;
}