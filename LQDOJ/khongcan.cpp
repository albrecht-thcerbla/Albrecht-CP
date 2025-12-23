#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  long long a, b, c; cin >> a >> b >> c;
  if (a == b || b == c || a == c) return cout << "NO", 0;
  if (a + b > c && b + c > a && a + c > b) cout << "YES";
  else cout << "NO";
  return 0;
}