#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int maxn = 1e5 + 7;

bool isRBS(const string &s) {
  int bal = 0;
  for (char c : s) {
    if (c == '(') ++bal;
    else --bal;
    if (bal < 0) return false;
  }
  return bal == 0;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt; cin >> tt;
  while (tt--) {
    int n;
    string s;
    cin >> n >> s;
    if (n % 2 == 1) {
      cout << -1 << '\n';
      continue;
    }
    if (isRBS(s)) {
      cout << s << '\n';
      continue;
    }
    int open = 0;
    for (char c : s) {
      if (c == '(') ++open;
    }
    int targetHalf = n / 2;
    if ((open % 2) != (targetHalf % 2)) {
      cout << -1 << '\n';
      continue;
    }
    bool hasEq = false;
    for (int i = 0; i + 1 < n; ++i) {
      if (s[i] == s[i + 1]) {
        hasEq = true;
        break;
      }
    }
    if (!hasEq) {
      cout << -1 << '\n';
      continue;
    }
    queue<string> q;
    unordered_set<string> seen;
    q.push(s);
    seen.insert(s);
    string ans = "-1";
    while (!q.empty()) {
      string cur = q.front();
      q.pop();

      if (isRBS(cur)) {
        ans = cur;
        break;
      }
      for (int i = 0; i + 1 < n; ++i) {
        if (cur[i] == '(' && cur[i + 1] == '(') {
          string nxt = cur;
          nxt[i] = nxt[i + 1] = ')';
          if (!seen.count(nxt)) {
            seen.insert(nxt);
            q.push(nxt);
          }
        } else if (cur[i] == ')' && cur[i + 1] == ')') {
          string nxt = cur;
          nxt[i] = nxt[i + 1] = '(';
          if (!seen.count(nxt)) {
            seen.insert(nxt);
            q.push(nxt);
          }
        }
      }
      if (seen.size() > 200000) break;
    }
    cout << ans << '\n';
  }
  return 0;
}
