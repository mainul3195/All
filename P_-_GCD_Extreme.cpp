#include <bits/stdc++.h>
using namespace std;
#define lim 1000003
long long ans[1000006], phi[lim + 3];
void make_ans()
{
    for (int i = 0; i <= lim; i++)
        phi[i] = i;
    phi[1] = 1;
    for (int i = 2; i <= lim; i++)
        if (phi[i] == i)
            for (int j = i; j <= lim; j += i)
                phi[j] -= phi[j] / i;
    for (int i = 1; i <= lim; i++)
        for (int j = i; j <= lim; j += i)
            ans[j] += phi[i] * j / i;
    for (int j = 1; j <= lim; j++)
        ans[j] += ans[j - 1] - j;
    return;
}
void solve()
{
    int n;
    while (cin >> n && n)
        cout << ans[n] << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    make_ans();
    solve();
    return 0;
}