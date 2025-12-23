#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  double n; cin >> n;
  double sum = n + n * 0.05;
  for (int i = 1; i <= 10; i++) {
    cout << fixed << setprecision(3) << sum << '\n';
    sum += (sum * 0.05);
  }
  return 0;
}