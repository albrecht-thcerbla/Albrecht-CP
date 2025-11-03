#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;
 
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  int a[n + 1], b[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b + 1, b + n + 1);
  for (int i = 1; i <= n; i++) {
    if (a[i] != b[i] && a[n - i + 1] != b[i]) return cout << "NO", 0;
  }
  cout << "YES";
  return 0;
}