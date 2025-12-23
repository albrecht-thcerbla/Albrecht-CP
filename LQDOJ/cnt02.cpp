#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  map<int, int> mp;
  set<int> se;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    se.insert(x);
    mp[x]++;
  }
  for (auto it : se) {
    cout << it << " " << mp[it] << '\n';
  }            
  return 0;
}