#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int tong_hai_so(int a, int b) {
  return (a + b);
}
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int a, b; cin >> a >> b;
  cout << tong_hai_so(a, b);
  return 0;
}