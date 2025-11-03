#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int a, b; cin >> a >> b;
  if (a > b) swap(a, b);
  cout << 1 << " ";
  for (int i = 2; i <= a; i++) {
    if (a % i == 0 && b % i == 0) cout << i << " ";
  }
  if (b % a == 0) cout << a;
  return 0;
}