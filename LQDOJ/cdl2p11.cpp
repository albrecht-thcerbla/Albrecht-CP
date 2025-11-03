#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  double k, h; cin >> k >> h;
  double bmi = k / (h * h);
  if (bmi > 22.9) cout << "Thua can";
  else if (bmi < 18.8) cout << "Thieu can";
  else cout << "Binh thuong"; 
  return 0;
}