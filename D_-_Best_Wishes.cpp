#include <bits/stdc++.h>
using namespace std;
vector<int> ans(1000006, 0), par(1000006);
void print(int n)
{
    if (n == 1)
    {
        cout << "1 ";
        return;
    }
    print(par[n]);
    cout << n << " ";
}
void solve()
{
    int n;
    cin >> n;
    cout << ans[n] << "\n";
    print(n);
    cout << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ans[1] = 1;
    par[1] = 1;
    for (int i = 2; i <= 1000000; i++)
    {
        int tmp = ans[i - 1], pr = i - 1;
        if (i % 2 == 0 && ans[i / 2] < tmp)
        {
            tmp = ans[i / 2];
            pr = i / 2;
        }
        if (i % 3 == 0 && ans[i / 3] < tmp)
        {
            tmp = ans[i / 3];
            pr = i / 3;
        }
        ans[i] = tmp + 1;
        par[i] = pr;
    }
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}