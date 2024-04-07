#include <bits/stdc++.h>
using namespace std;
string str;
int palin[1003][1003], dp[1003];
bool make_palin(int s = 0, int e = str.size() - 1)
{
    if (e == s + 1)
    {
        palin[s][s] = palin[e][e] = 1;
        return palin[s][e] = (str[s] == str[e]);
    }
    if (s == e)
        return palin[s][e] = 1;
    if (~palin[s][e])
        return palin[s][e];
    make_palin(s + 1, e);
    make_palin(s, e - 1);
    return palin[s][e] = (str[s] == str[e] && palin[s + 1][e - 1]);
}
void solve()
{
    memset(palin, -1, sizeof(palin));
    for (int i = 0; i < 1003; i++)
        dp[i] = i;
    cin >> str;
    for (int i = 0; i < str.size(); i++)
        palin[i][i] = 1;
    make_palin();
    for (int i = 2; i <= str.size(); i++)
        for (int j = 1; j <= i; j++)
            if (palin[j - 1][i - 1] == 1)
                dp[i] = min(dp[i], dp[j - 1] + 1);
    cout << dp[str.size()] << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}