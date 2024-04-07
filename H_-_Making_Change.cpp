#include <bits/stdc++.h>
using namespace std;
vector<int> val = {1, 2, 4, 10, 20, 40}, avail, forsk, forme;
double dtot;
int tot;
void solve()
{
    forsk = vector<int>(1001);
    for (auto &i : forsk)
        i = 100000000;
    forsk[0] = 0;
    for (auto v : val)
    {
        for (int i = v; i <= 1000; i++)
            forsk[i] = min(forsk[i], forsk[i - v] + 1);
    }
    // for (int i = 0; i < 20; i++)
    //     cout << forsk[i] << "\n";
    while (1)
    {
        // cout << "HERE" << endl;
        avail = vector<int>(6);
        int oor = 0;
        for (auto &i : avail)
        {
            cin >> i;
            // cout << i << " ";
            oor |= i;
        }
        // cout << "\n";
        if (!oor)
            return;
        cin >> dtot;
        tot = dtot * 20;
        // cout << tot << endl;
        forme = vector<int>(1001);
        for (auto &i : forme)
            i = 100000000;
        forme[0] = 0;
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < avail[i]; j++)
                for (int k = 1000; k >= val[i]; k--)
                    forme[k] = min(forme[k], forme[k - val[i]] + 1);
        int ans = 100000000;
        for (int i = tot; i <= 1000; i++)
            ans = min(ans, forme[i] + forsk[i - tot]);
        // for (int i = tot; i <= tot + 10; i++)
        //     cout << forme[i] << " " << forsk[i - tot] << "\n";
        printf("%3d\n", ans);
    }
}
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    solve();
    return 0;
}