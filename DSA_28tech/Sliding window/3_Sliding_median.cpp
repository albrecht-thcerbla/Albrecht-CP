#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

/**
  Proposed algorithm: sliding window technique.
  Case 1: Odd.
  + Insert 1 number >= median: iterator keep unchanged.
  + Insert 1 number <  median: iterator--.

  + Delete 1 number < median: iterator keep unchanged.
  + Delete 1 number > median: iterator--.
  + Delete 1 number = median: 
      + if iterator2 != iterator: iterator keep unchanged.
      + if iterator2 == iterator: iterator--.

  Case 2: Even
  + Insert 1 number >= median: iterator++.
  + Insert 1 number < median : iterator keep unchanged.

  + Delete 1 number <= median: iterator++.
  + Delete 1 number > median : iterator keep unchanged.
   (Because iterator2 != iterator => ++iterator AND iterator2 == iterator => ++iterator).

**/
  
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, k; cin >> n >> k;
  vector<int> a(n + 1);
  for (int i = 0; i < n; i++) cin >> a[i];
  multiset<int> ms;
  for (int i = 0; i < k; i++) ms.insert(a[i]);
  auto it = ms.begin(); 
  for (int i = 0; i < (k - 1 >> 1); i++) ++it;
  cout << *it << " ";
  if (k & 1) {
    for (int i = k; i < n; i++) {
      ms.insert(a[i]); // odd
      if (a[i] < *it) --it;
      auto it_del = ms.lower_bound(a[i - k]);
      if (*it_del <= *it) ++it; //even
      ms.erase(it_del);
      cout << *it << " ";
    }
  } else {
    for (int i = k; i < n; i++) {
      ms.insert(a[i]); //even
      if (a[i] >= *it) ++it;
      auto it_del = ms.lower_bound(a[i - k]);
      if (*it_del > *it) --it;
      else if (*it_del == *it) --it;
      ms.erase(it_del);
      cout << *it << " ";
    }
  }

  return 0;
}