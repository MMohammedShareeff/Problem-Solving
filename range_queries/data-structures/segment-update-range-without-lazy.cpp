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
    int sum, updates;
    Node() {
        sum = 0;
        updates = 0;
    }
    Node(int x) {
        sum = x;
        updates = 0;
    }
};

struct SegTree {
    int tree_size;
    vector<Node> data;
    SegTree(int n) {
        tree_size = 1;
        while (tree_size < n) tree_size <<= 1;
        data.assign(2 * tree_size, Node());
    }

    void build(const vector<int> & arr, int node, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < arr.size())
                data[node] = Node(arr[lx]);
            return;
        }

        int mid = (lx + rx) / 2;
        build(arr, 2 * node + 1, lx, mid);
        build(arr, 2 * node + 2, mid, rx);
    }

    void build(const vector<int> & arr) {
        build(arr, 0, 0, tree_size);
    }

    void update(int l, int r, int val, int node, int lx, int rx) {
        if (lx >= r or rx <= l)
            return;
        if (lx >= l and rx <= r) {
            data[node].updates += val;
            return;
        }

        int mid = (lx + rx) / 2;
        update(l, r, val, 2 * node + 1, lx, mid);
        update(l, r, val, 2 * node + 2, mid, rx);
    }

    void update(int l, int r, int val) {
        update(l, r, val, 0, 0, tree_size);
    }

    int get(int idx, int node, int lx, int rx) {
        if (rx - lx == 1) {
            return data[node].updates + data[node].sum;
        }

        int mid = (lx + rx) / 2;
        if (idx < mid) {
            return get(idx, 2 * node + 1, lx, mid) + data[node].updates;
        }
        else {
            return get(idx, 2 * node + 2, mid, rx) + data[node].updates;
        }
    }

    int get(int idx) {
        return get(idx, 0, 0, tree_size);
    }
};

// problem link: https://cses.fi/alon/task/1651
void solve()
{
    int n, q; cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    SegTree tree(n);
    tree.build(arr);

    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int a, b, u; cin >> a >> b >> u;
            a--;
            tree.update(a, b, u);
        }
        else {
            int k; cin >> k;
            k--;
            cout << tree.get(k) << endl;
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