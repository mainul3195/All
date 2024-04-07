#include <bits/stdc++.h>
using namespace std;
int base, k;
string s;
long long dp[1 << 12 + 2][20 + 2];
map<char, int> mp;
long long okdone(int mask = 0, int mod = 0)
{
    int i = __builtin_popcount(mask);
    if(i==s.size())
        return mod==0;
    if(~dp[mask][mod])
        return dp[mask][mod];
    long long ans = 0;
    for(int pos = 0; pos<s.size(); pos++)
        if(!(mask&(1LL<<pos)))
            ans += okdone(mask | (1LL<<pos), (mod*base+mp[s[pos]])%k);
    return dp[mask][mod] = ans;
}
void solve()
{
    cin >> base >> k >> s;
    memset(dp, -1, sizeof(dp));
    cout << okdone() << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    mp['0'] = 0;
    mp['1'] = 1;
    mp['2'] = 2;
    mp['3'] = 3;
    mp['4'] = 4;
    mp['5'] = 5;
    mp['6'] = 6;
    mp['7'] = 7;
    mp['8'] = 8;
    mp['9'] = 9;
    mp['A'] = 10;
    mp['B'] = 11;
    mp['C'] = 12;
    mp['D'] = 13;
    mp['E'] = 14;
    mp['F'] = 15;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}