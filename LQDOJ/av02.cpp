#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    if (x & 1) sum += x;
  }
  cout << sum;
  return 0;
}