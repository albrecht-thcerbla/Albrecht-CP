#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int a, b, u, v, x, y; cin >> a >> b >> u >> v >> x >> y;
  int adult = x - y;
  long long price = a * adult + b * y + u * adult + v * y;
  cout << "Tong so tien ve: " << price << " nghin dong.";
  return 0;
}