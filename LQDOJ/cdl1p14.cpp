#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int a, b, c; cin >> a >> b >> c;
  int sum = 0;
  if (a & 1) a++;
  if (b & 1) b++;
  if (c & 1) c++;
  sum += (a >> 1) + (b >> 1) + (c >> 1);
  cout << "So ban toi thieu can mua: " << sum;
  return 0;
}