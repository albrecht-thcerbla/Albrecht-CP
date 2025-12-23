#include <bits/stdc++.h>
using namespace std;

/**
* To use this, we need to go to "C:\MinGW\lib\gcc\mingw32\6.3.0\include\c++\ext\pb_ds\detail\resize_policy". Then rename the file "hash_standard_resize_policy_imp.hpp0000064" to "hash_standard_resize_policy_imp.hpp".
* - order_of_key (k) : Number of items strictly smaller than k.
* - find_by_order(k) : k-th element in a set (counting from zero).
* Along with the previous operations of the set, it supports two main important operations.
* +) find_by_order(k): It returns to an iterator to the kth element (counting from zero) in the set in O(logn) time. To find the first element k must be zero.
* +) order_of_key(k) : It returns to the number of items that are strictly smaller than our item k in O(logn) time.
* +) count of elements between l and r can be found by: o_set.order_of_key(r+1) – o_set.order_of_key(l).
* ref: https://www.geeksforgeeks.org/ordered-set-gnu-c-pbds
* ref: https://www.spoj.com/problems/ORDERSET
**/

/**------------------------------------------------------**/

//order_of_key (k) : Number of items strictly smaller than k.
//find_by_order(k) : k-th element in a set (counting from zero).
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

/**------------------------------------------------------**/

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt; cin >> tt;
  pbds<int> s;
  while (tt--) {
    char c; cin >> c;
    int n; cin >> n;
    if (c == 'I') s.insert(n);
    else if (c == 'D') s.erase(n);
    else if (c == 'C') cout << s.order_of_key(n) << '\n';
    else if (c == 'K') {
      if (n > sz(s)) cout << "invalid" << '\n';
      else cout << *s.find_by_order(n - 1) << '\n';
    }
  }
  return 0;
}
