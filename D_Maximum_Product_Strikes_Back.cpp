#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    int i = 0;
    int mx = 0, lft = n + 1, rt = -1;
    while (i < n)
    {
        if (v[i] == 0)
        {
            i++;
            continue;
        }
        int s = i, ns = n + 1, ne = -1, bn = 0, an = 0, tn = 0, tot = 0;
        while (i < n && v[i])
        {
            if (v[i] < 0)
            {
                tn++;
                if (ns == n + 1)
                    ns = i;
                ne = i;
                an = 0;
            }
            if (v[i] % 2 == 0)
            {
                if (i <= ns)
                    bn++;
                an++;
                tot++;
            }
            i++;
        }
        // cout << ns << " " << ne << " " << bn << " " << an << " " << tot << "\n";
        int e = i - 1;
        if (tn % 2 != 0)
        {
            if (bn < an)
            {
                tot -= bn;
                s = ns + 1;
            }
            else
            {
                tot -= an;
                e = ne - 1;
            }
        }
        if (tot > mx)
        {
            mx = tot;
            lft = s;
            rt = e;
        }
        i++;
    }
    if (!mx)
        cout << "0 " << n << "\n";
    else
        cout << lft << " " << n - rt - 1 << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}