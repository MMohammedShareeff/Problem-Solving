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

struct BIT {
	int n;
	vector<int> v;

	BIT(int _n) {
		n = _n;
		v.assign(n + 1, 0);
	}

	int get(int idx) {
		int pref = 0;
		while (idx > 0) {
			pref += v[idx];
			idx -= (idx & -idx);
		}
		return pref;
	}

	void update(int idx, int val) {
		while (idx <= n) {
			v[idx] += val;
			idx += (idx & -idx);
		}
	}

	int get(int l, int r) {
		return get(r) - get(l - 1);
	}

	int get_idx(int idx) {
		return get(idx) - get(idx - 1);
	}

	void set(int idx, int val) {
		int old = get_idx(idx);
		update(idx, -old + val);
	}
};

// classical problem - Range Update Queries
// link: https://cses.fi/alon/task/1651

void solve()
{
	int n, q; cin >> n >> q;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	BIT bit(n);

	while (q--) {
		int type; cin >> type;
		if (type == 1) {
			int l, r, u; cin >> l >> r >> u;
			bit.update(l, u);
			bit.update(r + 1, -u);
		}
		else {
			int k; cin >> k;
			cout << bit.get(k) + v[k] << endl;
		}
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