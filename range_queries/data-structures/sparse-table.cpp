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

struct ST {
	vector<vector<int>> data;
	vector<int> logs;

	int merge(int l, int r) {
		return min(l, r);
	}

	int get(int l, int r) {
		int len = r - l + 1;
		int level = logs[len];
		return merge(data[level][l], data[level][r - (1 << level) + 1]);
	}

	ST(vector<int> &arr) {
		int n = size(arr);

		logs.assign(n + 1, 0);
		for (int i = 2; i <= n; i++) {
			logs[i] = logs[i / 2] + 1;
		}

		data.assign(logs[n] + 1, vector<int>(n));
		data[0] = arr;

		for (int i = 1; i <= logs[n]; i++) {
			int len = 1 << i;
			for (int j = 0; j + len <= n; j++) {
				data[i][j] = merge(data[i - 1][j], data[i - 1][j + (len >> 1)]);
			}
		}
	}
};

void solve()
{
	// get the minimmum within a range [l, r]
	// just change within the merge to get everything else
	// overlapping should not effect the final answer to be able to use sparse table
	// gcd(2, 3) = gcd(2, 3, 2) while sum(2, 3) != sum(2, 3, 2) so we can not use sparse with
	int n, q; cin >> n >> q;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	ST table(v);
	while (q--) {
		int l, r; cin >> l >> r;
		l--, r--;
		cout << table.get(l, r) << endl;
	}
	cout << endl;
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