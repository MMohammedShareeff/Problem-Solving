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

struct Node {
	int sum;
	Node () {
		sum = 0;
	}
	Node (int val) {
		sum = val;
	}
};

struct SegTree {
	int tree_size;
	vector<Node> data;

	SegTree(int n) {
		tree_size = 1;
		while (tree_size < n) {
			tree_size <<= 1;
		}

		data.assign(2 * tree_size, Node());
	}

	Node merge(const Node & lft, const Node & ryt) {
		return Node(lft.sum + ryt.sum);
	}

	void build(const vector<int> & arr, int node, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < arr.size()) {
				data[node] = Node(arr[lx]);
			}
			return;
		}

		int base = 2 * node;
		int mid = lx + (rx - lx ) / 2;

		build(arr, base + 1, lx, mid);
		build(arr, base + 2, mid, rx);

		data[node] = merge(data[base + 1], data[base + 2]);
	}

	void build(const vector<int> & arr) {
		build(arr, 0, 0, tree_size);
	}

	void set(int idx, int val, int node, int lx, int rx) {
		if (rx - lx == 1) {
			data[node] = Node(val);
			return;
		}

		int base = 2 * node;
		int mid = lx + (rx - lx) / 2;

		if (idx < mid) {
			set(idx, val, base + 1, lx, mid);
		}
		else {
			set(idx, val, base + 2, mid, rx);
		}

		data[node] = merge(data[base + 1], data[base + 2]);
	}

	void set(int idx, int val) {
		set(idx, val, 0, 0, tree_size);
	}

	Node get(int l, int r, int node, int lx, int rx) {
		if (lx >= r or rx <= l) {
			return Node();
		}
		if (lx >= l and rx <= r) {
			return data[node];
		}

		int base = 2 * node;
		int mid = lx + (rx - lx) / 2;

		Node lft = get(l, r, base + 1, lx, mid);
		Node ryt = get(l, r, base + 2, mid, rx);

		return merge(lft, ryt);
	}

	int get(int l, int r) {
		return get(l, r, 0, 0, tree_size).sum;
	}

	int lower_bound(int x, int l, int r, int node, int lx, int rx) {
		if (rx <= l or lx >= r or data[node].sum < x) {
			return -1;
		}
		if (rx - lx == 1) {
			return lx;
		}

		int mid = lx + (rx - lx) / 2;
		int res = lower_bound(x, l, r, 2 * node + 1, lx, mid);
		if (res != -1) {
			return res;
		}
		return lower_bound(x, l, r, 2 * node + 2, mid, rx);
	}

	int lower_bound(int x, int l = 0, int r = -1) {
		if (r == -1) {
			r = tree_size;
		}
		return lower_bound(x, l, min(r, tree_size), 0, 0, tree_size);
	}
};


// problem link: https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/A
// update points and get summation in a range.
void solve()
{
	int n, q; cin >> n >> q;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	SegTree tree(n);
	tree.build(v);

	while (q--) {
		int type; cin >> type;
		if (type == 1) {
			int i, v; cin >> i >> v;
			tree.set(i, v);
		}
		else {
			int l, r; cin >> l >> r;
			cout << tree.get(l, r) << endl;
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