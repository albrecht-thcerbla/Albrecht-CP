#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int n;
string s, res;
string a[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
char x[10];

void backtrack(int i, string res) {
  int num = s[i] ^ '0';
  for (char c : a[num]) {
    x[i] = c;
    if (i == n) {
      cout << res + c << " ";
    }
    backtrack(i + 1, res + c);
  }
}
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> s;
  n = sz(s);
  s = " " + s;
  backtrack(1, "");  
  return 0;
}
