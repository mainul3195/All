#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    int len = 2000000000;
    int s = -1, e = -1;
    int ar[n + 1], taken[100005] = {0};
    for (int i = 1; i <= n; i++)
        cin >> ar[i];
    int dif = 0;
    for (int i = 1, j = 1; i <= n && j <= n;)
    {
        if (!taken[ar[i]])
            dif++;
        taken[ar[i++]]++;
        if (dif == k)
        {
            while ((j <= n) && taken[ar[j]]>1)
                taken[ar[j++]]--;
            int tlen = i - j;
            if (tlen < len)
            {
                len = tlen;
                s = j;
                e = i - 1;
            }
            taken[ar[j++]]--;
            dif--;
        }
    }
    cout << s << " " << e << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}