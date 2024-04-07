#include <bits/stdc++.h>
using namespace std;
vector<int> reform;
void solve()
{
    string s[3];
    cin >> s[1] >> s[2];
    int mismatched = 0;
    for (int i = 0; i < s[1].size(); i++)
        mismatched += s[1][i] != s[2][i];
    int t, q;
    cin >> t >> q;
    reform = vector<int>(q + 1 + t, -1);
    int time = 0;
    while (q--)
    {
        if (~reform[time])
        {
            int ind = reform[time];
            mismatched += (s[1][ind] != s[2][ind]);
        }
        int type;
        cin >> type;
        if (type == 3)
        {
            if (mismatched)
                cout << "NO\n";
            else
                cout << "YES\n";
        }
        else if (type == 1)
        {
            int ind;
            cin >> ind;
            ind--;
            reform[time + t] = ind;
            mismatched -= (s[1][ind] != s[2][ind]);
        }
        else
        {
            int a, i1, b, i2;
            cin >> a >> i1 >> b >> i2;
            i1--, i2--;
            if (a == b)
            {
                int bm = (s[1][i1] != s[2][i1]) + (s[1][i2] != s[2][i2]);
                char tmp = s[a][i1];
                s[a][i1] = s[b][i2];
                s[b][i2] = tmp;
                int am = (s[1][i1] != s[2][i1]) + (s[1][i2] != s[2][i2]);
                mismatched += am - bm;
            }
            else
            {
                int bm = (s[a][i1] != s[b][i1]) + (s[a][i2] != s[b][i2]);
                char tmp = s[a][i1];
                s[a][i1] = s[b][i2];
                s[b][i2] = tmp;
                int am = (s[a][i1] != s[b][i1]) + (s[a][i2] != s[b][i2]);
                mismatched += am - bm;
            }
        }
        time++;
    }
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