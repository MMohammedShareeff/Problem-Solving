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

string getBinary(int n) {
    string bin = "";
    while (n / 2 != 0) {
        bin.push_back(to_string(n % 2)[0]);
        n /= 2;
    }

    bin.push_back(to_string(n)[0]);
    reverse(bin.begin(), bin.end());
    return bin;
}

string convTo32Binary(int decimal) {
    string binary = getBinary(decimal);

    string binary32(32, '0');
    for (int i = 31, j = binary.size() - 1; j >= 0; i--, j--) {
        binary32[i] = binary[j];
    }

    return binary32;
}

int XOR(int a, int b) {
    string bina = convTo32Binary(a);
    string binb = convTo32Binary(b);

    int ans = 0;
    for (int i = 31, weight = 1; i >= 0; i--, weight *= 2) {
        if (bina[i] != binb[i]) {
            ans += weight;
        }
    }

    return ans;
}

void solve()
{
    int a, b; cin >> a >> b;
    cout << XOR(a, b);
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