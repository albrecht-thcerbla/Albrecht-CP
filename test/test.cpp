#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;
int n, h, q;

// Tính tổng 0 + 1 + 2 + ... + a (mod MOD)
inline long long sum_upto(int a) {
    return (1LL * a * (a + 1) / 2) % MOD;
}

struct SegmentTree {
    static const int MAX = 100000;
    long long tree[2 * MAX];         // Segment tree
    long long lazy_add[MAX];         // Giá trị khởi đầu cần thêm (dạng cấp số cộng)
    long long lazy_inc[MAX];         // Tỉ số cấp số cộng cần thêm

    // Cập nhật nút `i` dựa trên 2 con + giá trị lazy hiện tại
    void recalc(int i, int len) {
        tree[i] = (tree[2 * i] + tree[2 * i + 1] + len * lazy_add[i] + sum_upto(len - 1) * lazy_inc[i]) % MOD;
    }

    // Apply update trực tiếp lên nút `i` (không đệ quy)
    void apply(int i, long long add, long long inc, int len) {
        tree[i] = (tree[i] + len * add + sum_upto(len - 1) * inc) % MOD;
        if (i < n) {
            lazy_add[i] = (lazy_add[i] + add) % MOD;
            lazy_inc[i] = (lazy_inc[i] + inc) % MOD;
        }
    }

    // Đẩy giá trị lazy từ gốc xuống l, r (theo chiều top-down)
    void push_down(int l, int r) {
        int depth = h;
        int seg_len = 1 << (h - 1);  // chiều dài đoạn con ở level h

        l += n; r += n - 1;
        for (; depth; --depth, seg_len /= 2) {
            for (int i = l >> depth; i <= r >> depth; ++i) {
                if (lazy_add[i] != 0 || lazy_inc[i] != 0) {
                    apply(2 * i, lazy_add[i], lazy_inc[i], seg_len);
                    apply(2 * i + 1, (lazy_add[i] + lazy_inc[i] * seg_len) % MOD, lazy_inc[i], seg_len);
                    lazy_add[i] = lazy_inc[i] = 0;
                }
            }
        }
    }

    // Cập nhật ngược từ l và r để cập nhật lại các tổ tiên
    void push_up(int l, int r) {
        int len = 1;
        l += n; r += n - 1;
        while (l > 1) {
            l /= 2; r /= 2; len *= 2;
            for (int i = r; i >= l; --i)
                recalc(i, len);
        }
    }

    // Cập nhật đoạn [l, r) với cấp số cộng: init + inc, init + inc*1, ...
    void update(int l, int r, long long init, long long inc) {
        push_down(l, l + 1);
        push_down(r - 1, r);

        int left_offset = 0;
        int right_offset = r - l;
        int len = 1;

        for (int L = l + n, R = r + n; L < R; L /= 2, R /= 2, len *= 2) {
            if (L & 1) {
                apply(L++, (init + inc * left_offset) % MOD, inc, len);
                left_offset += len;
            }
            if (R & 1) {
                R--;
                apply(R, (init + inc * (right_offset - len)) % MOD, inc, len);
                right_offset -= len;
            }
        }

        push_up(l, l + 1);
        push_up(r - 1, r);
    }

    // Truy vấn tổng đoạn [l, r)
    long long query(int l, int r) {
        push_down(l, l + 1);
        push_down(r - 1, r);

        long long result = 0;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) result = (result + tree[l++]) % MOD;
            if (r & 1) result = (result + tree[--r]) % MOD;
        }
        return result;
    }

} st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    cin >> n >> q;
    // Tính độ sâu của cây segment tree (h = log2(n))
    h = 32 - __builtin_clz(n);

    while (q--) {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1) {
            int a, b;
            cin >> a >> b;
            st.update(l - 1, r, b, a);
        } else {
            cout << st.query(l - 1, r) << '\n';
        }
    }
}
