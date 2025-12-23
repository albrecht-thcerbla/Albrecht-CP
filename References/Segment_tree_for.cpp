/** author : albrecht **/
#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

/**
	Sử dụng t[n * 2] thay vì t[n * 4]
	Cây nhị phân đầy đủ chứa:
		- Node lá nằm từ chỉ số n đến 2n-1
		- Node cha nằm từ chỉ số 1 đến n-1 (mỗi node cha là tổng của 2 con trái và phải)
 **/

int n, q, size = 1;
int a[maxn];
int64_t t[maxn * 2];

void build() {
	// xây node lá
	for (int i = 0; i < n; i++) t[n + i] = a[i];

	// xây node cha
	for (int i = n - 1; i > 0; i--) t[i] = t[i << 1] + t[i << 1 | 1];
	// bắt đầu từ n - 1 về 1 và mỗi node cha sẽ là tổng của 2 con.
}

int64_t query(int l, int r) {
	int64_t res = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res += t[l++];
		if (r & 1) res += t[--r];
	}
	return res;
}

void modify(int p, int val) {
	for (t[p += n] = val; p > 1; p >>= 1) t[p >> 1] = t[p] + t[p ^ 1];
	// cập nhật cha p / 2 = tổng 2 con
	// p^1 là node bên cạnh
	// nếu p chẵn thì p^1 = p + 1 ngược lại thì = p - 1
}

int32_t main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);
  cin >> n >> q;
  for (int i = 0; i < n; i++) cin >> a[i];
  build();
	while (q--) {
		int ty; cin >> ty;
		if (ty == 1) {
			int pos, val; cin >> pos >> val;
			modify(pos - 1, val);
		} else {
			int l, r; cin >> r;
			cout << query(0, r) << '\n';
		}
	}
  return 0;
}
