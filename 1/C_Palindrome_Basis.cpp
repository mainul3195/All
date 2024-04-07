#include <bits/stdc++.h>
using namespace std;
vector<int> pals, dp(40004, 0);
#define mod 1000000007
bool isPal(int n)
{
    int tmp = n, rev = 0;
    while (tmp)
    {
        int r = tmp % 10;
        tmp /= 10;
        rev = rev * 10 + r;
    }
    return rev == n;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 1; i < 40004; i++)
        if (isPal(i))
            pals.push_back(i);
    dp[0] = 1;
    for (auto i : pals)
    {
        for (int j = i; j < 40004; j++)
            dp[j] = (dp[j]+ dp[j - i])%mod;
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }
    return 0;
}