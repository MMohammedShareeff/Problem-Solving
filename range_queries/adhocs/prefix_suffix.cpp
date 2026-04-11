#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define endl '\n'
#define int long long

using ld = long double;
using ll = long long;

using namespace std;
using namespace __gnu_pbds;
template <class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int dx[] = {-1, +1, +0, +0, -1, +1, -1, +1};
int dy[] = {+0, +0, -1, +1, +1, -1, -1, +1};

const double PI = 4 * atan(1);

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n + 1, 0), pref(n + 2, 0), suff(n + 2, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    // prefix
    for (int i = 1; i <= n; i++)
    {
        pref[i] = v[i - 1] + pref[i - 1];
    }

    // suffix
    for (int i = n - 1; i >= 0; i--)
    {
        suff[i] = v[i] + suff[i + 1];
    }

    for (int i = 1; i <= n; i++)
    {
        cout << pref[i] << " " << suff[i] << endl;
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