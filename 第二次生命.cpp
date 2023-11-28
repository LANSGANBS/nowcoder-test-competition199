#include <bits/stdc++.h>
#define endl '\n'
#define buff ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
/*
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize(3)
*/
using namespace std;
#define ll long long
#define int ll
const int N = 1e6 + 5;
int n,l,k;
int w[N];

void solve()
{
    cin >> n >> l >> k;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    sort(w + 1, w + 1 + n);
    int ans = 0;
    for (int i = 2; i <= n; i++)
        ans = max(ans, w[i] - w[i - 1]);
    ans = max(ans, (w[1] - w[n] + l) % l);
    for (int i = 1; i <= n; i++)
    {
        int res = 0;
        if (i <= k + 1)
        {
            int last = k - (i - 1);
            last = n - last;
            res = (w[i] - w[last] + l) % l; // 处理跑到后面去了
        }
        else
        {
            int last = i - k - 1;
            res = (w[i] - w[last] + l) % l;
        }
        ans = max(ans, res);
    }
    cout << ans << endl;
    // wout <<L" "<<endl;
    // cout << R"( )" << endl;
}

signed main()
{
    // setlocale(LC_ALL, "");
    buff;
    int t = 1;
    //	cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}