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

struct TreeNode {
	int sum = 0;
	TreeNode *left = nullptr, *right = nullptr;
	void update(int val) {
		sum += val;
	}
};

using Node = TreeNode*;

// instead of doing state compression - sometimes this will be better.
// complexity is O(q log n)
struct DynamicSegTree {
	int n;
	Node root;

	DynamicSegTree(int sz) {
		n = sz;
		root = new TreeNode();
	}

	void update(int idx, int &val, Node &node, int lx, int rx) {
		if (rx - lx == 1) {
			node->update(val);
			return;
		}

		int mid = (lx + rx) / 2;
		if (idx < mid) {
			if (node->left == nullptr) node->left = new TreeNode();
			update(idx, val, node->left, lx, mid);
		}
		else {
			if (node->right == nullptr) node->right = new TreeNode();
			update(idx, val, node->right, mid, rx);
		}

		node->sum = ((node->left == nullptr) ? 0 : node->left->sum) +
		            ((node->right == nullptr) ? 0 : node->right->sum);
	}
	void update(int idx, int val) {
		update(idx, val, root, 0, n);
	}

	int get(int l, int r, Node &node, int lx, int rx) {
		if (node == nullptr or lx >= r or rx <= l) return 0;
		if (lx >= l and rx <= r) return node->sum;

		int mid = (lx + rx) / 2;
		int L = get(l, r, node->left, lx, mid);
		int R = get(l, r, node->right, mid, rx);
		return L + R;
	}
	int get(int l, int r) {
		return get(l, r, root, 0, n);
	}
};

// problem link (CSES): https://cses.fi/problemset/task/1144
void solve()
{
	int n, q; cin >> n >> q;
	DynamicSegTree dtree(1e9 + 1);

	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dtree.update(arr[i], 1);
	}

	while (q--) {
		char type; cin >> type;
		if (type == '!') {
			int idx, val; cin >> idx >> val;
			idx--;
			dtree.update(arr[idx], -1);
			arr[idx] = val;
			dtree.update(arr[idx], 1);
		}
		else {
			int l, r; cin >> l >> r;
			cout << dtree.get(l, r + 1) << endl;
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