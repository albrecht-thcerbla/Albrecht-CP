#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string a, b; getline(cin, a); getline(cin, b);
  stringstream ss1(a);
  stringstream ss2(b);
  string w1, w2;
  int cnt1 = 0, cnt2 = 0;
  while (ss1 >> w1) ++cnt1;
  while (ss2 >> w2) ++cnt2;
  cout << cnt1 + cnt2;
  return 0;
}