#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  double h, w; cin >> w >> h;
  h /= 100;
  double bmi = w / (h * h);
  cout << "Chi so BMI:  ";
  cout << fixed << setprecision(2) << bmi;
  return 0;
}