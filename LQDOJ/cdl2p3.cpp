#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int a[3];
  for (int i = 0; i < 3; i++) {
    cin >> a[i];
    if (a[i] < 0) {
      return cout << "It nhat mot so am", 0;
    }
  }
  cout << "Ca ba so deu duong";
  return 0;
}