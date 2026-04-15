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

// coordinate-compression (1-indexed)
struct Compressor {

	vector<int> vals;

	void add(int x) {
		vals.push_back(x);
	}

	void build() {
		sort(vals.begin(), vals.end());
		vals.erase(unique(vals.begin(), vals.end()), vals.end());
	}

	int get(int x) {
		return (lower_bound(vals.begin(), vals.end(), x) - vals.begin()) + 1;
	}

	int original(int idx) {
		return vals[idx - 1];
	}

	int size() {
		return vals.size();
	}
};


void solve()
{
	// having a variable x for example that needs to be compressed and you will
	// any value will be used in the programm must be compressed (x -> x + 1, x - 1 should be compressed as well)

	// in freqency arrays for example you can not store a huge value like 1e9c
	// with coordinate-compression you compress the value to give it a smaller id
	// then to be able to use it in a frequency array.

	vector<int> v = {1, 3, 5, 7, 100000000};
	Compressor compressor;
	int n = v.size();
	for (int i = 0; i < n; i++) {
		compressor.add(v[i]);
	}

	compressor.build();
	cout << compressor.get(v[4]) << endl; // the range of values now from 1 to 5 instead of 1 to 100000000

	for (int i = 0; i < n; i++) {
		compressor.add(v[i] + 1);
	}

	cout << compressor.get(v[4]);
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

