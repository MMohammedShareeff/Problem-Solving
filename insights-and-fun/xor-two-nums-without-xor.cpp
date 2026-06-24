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

string binary(int n) {
    string bin = "";
    while (n / 2 != 0) {
        bin.push_back(to_string(n % 2)[0]);
        n /= 2;
    }
    bin.push_back(to_string(n)[0]);
    reverse(bin.begin(), bin.end());
    return bin;
}


void solve()
{
    int a, b; cin >> a >> b;
    string bina(32, '0');
    string binb(32, '0');

    string tmpa = binary(a);
    for (int i = 31, j = tmpa.size() - 1; j >= 0; i--, j--) {
        bina[i] = tmpa[j];
    }

    string tmpb = binary(b);
    for (int i = 31, j = tmpb.size() - 1; j >= 0; i--, j--) {
        binb[i] = tmpb[j];
    }

    string temp(32, '0');
    for (int i = 0; i < 32; i++) {
        temp[i] = (bina[i] == binb[i] ? '0' : '1');
    }

    int ans = 0;
    for (int i = 31, weight = 1; i >= 0; i--, weight *= 2) {
        if (temp[i] == '1') {
            ans += weight;
        }
    }

    cout << ans << endl;
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