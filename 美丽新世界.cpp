#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
int f[100];

int modPow(int base, int exp, int mod)
{
    base %= mod;
    int result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

void solve()
{
    int f1, f2, p, A, n;
    cin >> f1 >> f2 >> p >> A >> n;
    f[1] = f1;
    f[2] = f2;
    for (int i = 3; i <= n; ++i)
    {
        f[i] = (int)log2(modPow(f[i - 1], f[i - 2], p) + 1) + A;
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << f[i] << ' ';
    }
    cout << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}