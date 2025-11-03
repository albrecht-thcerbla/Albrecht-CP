#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  long long f[90];
  f[1] = f[2] = 1;
  for (int i = 3; i <= n; i++) f[i] = f[i - 1] + f[i - 2];
  for (int i = 1; i <= n; i++) cout << f[i] << " ";
  return 0;
}