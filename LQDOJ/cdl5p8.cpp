#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string s; cin >> s;
  string tmp;
  vector<string> v;
  for (int i = 0; i < sz(s); i++) {
    if (s[i] != '/') tmp += s[i];
    else {
      v.emplace_back(tmp);
      tmp = "";
    }
  }
  v.emplace_back(tmp);
  cout << "Ngay " << v[0] << " thang " << v[1] << " nam " << v[2];
  return 0;
}