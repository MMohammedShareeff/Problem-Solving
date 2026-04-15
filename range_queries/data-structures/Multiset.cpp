#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define endl '\n'
#define int long long

using ld = long double;
using ll = long long;

using namespace std;
using namespace __gnu_pbds;
template <class T> using ordered_multiset = tree <T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update >;

int dx[] = { -1, +1, +0, +0, -1, +1, -1, +1};
int dy[] = { +0, +0, -1, +1, +1, -1, -1, +1};

const double PI = 4 * atan(1);

// Multiset using fenwick tree - 1 Indexed
// Problem Link: https://codeforces.com/problemset/problem/1354/D
struct MultiSet {

	int n;
	vector<int> b;
	MultiSet (int sz) {
		n = 1;
		while (n < sz) n <<= 1;
		b.assign(n + 1, 0);
	}

	void add(int idx, int val) {
		while (idx <= n) {
			b[idx] += val;
			idx += idx & -idx;
		}
	}

	int get(int idx) {
		int res = 0;
		while (idx > 0) {
			res += b[idx];
			idx -= idx & -idx;
		}
		return res;
	}

	int get(int l, int r) {
		return get(r) - get(l - 1);
	}

	int get_idx(int idx) {
		return get(idx) - get(idx - 1);
	}

	int lower_bound(int sum) {
		int idx = 0;
		for (int step = n; step > 0; step >>= 1) {
			if (b[idx + step] < sum) {
				sum -= b[idx + step];
				idx += step;
			}
		}
		return idx + 1;
	}

	void insert(int val) {
		add(val, 1);
	}

	void insert(int val, int cnt) {
		add(val, cnt);
	}

	void erase(int val) {
		int cnt = get_idx(val);
		if (cnt)
			add(val, -1);
	}

	void erase(int val, int cnt) {
		int mx = get_idx(val);
		cnt = min(cnt, mx);
		add(val, -cnt);
	}

	int operator[](int idx) {
		return lower_bound(idx);
	}

	int size() {
		return b[n];
	}
};

void solve()
{
	int n, q; cin >> n >> q;
	MultiSet MS(n);

	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		MS.insert(x);
	}

	while (q--) {
		int k; cin >> k;
		if (k > 0) {
			MS.insert(k);
		}
		else {
			k *= -1;
			int val = MS[k];
			MS.erase(val);
		}
	}

	if (MS.size()) {
		cout << MS[1] << endl;
	}
	else {
		cout << 0 << endl;
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("C:\\Users\\user\\Desktop\\inoutfiles\\in.txt", "r", stdin);
	freopen("C:\\Users\\user\\Desktop\\inoutfiles\\out.txt", "w", stdout);
#endif

	int t = 1;
	// int t; cin >> t;
	for (int i = 1; i <= t; i++)
	{
		solve();
	}

	cerr << "where is my keyboard?!!\n";
}