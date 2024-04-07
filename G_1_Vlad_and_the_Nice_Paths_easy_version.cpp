#include <bits/stdc++.h>
using namespace std;
#define max_lim 1000000
#define Mod 1000000007
vector<long long>f(max_lim+1);
void precalc()
{
    f[0]=1;
    for(long long i=1; i<=max_lim; i++)
        f[i]=f[i-1]*i%Mod;
    return;
}
long long bigMod(long long b, long long p)
{
    if(!p) return 1;
    if(p&1) return (b*bigMod(b, p-1))%Mod;
    long long T = bigMod(b, p/2);
    return (T*T)%Mod;
}
long long modInverse(long long n)
{
    return bigMod(n, Mod-2);
}
long long nCr(long long n, long long r)
{
    if(r>=n)
        return 1;
    return (((f[n]*modInverse(f[r]))%Mod)*modInverse(f[n-r]))%Mod;
}
vector<vector<long long>> dp, cnt;
vector<int> ar;
long long find(int s, int e, int i)
{
    if (!s)
        return cnt[i][e];
    return cnt[i][e] - cnt[i][s - 1];
}
int n, k;
long long okdone(int i, int c)
{
    if (!c)
        return 1;
    if (i < 0)
        return 0;
    if (~dp[i][c])
        return dp[i][c];
    long long tot = okdone(i-1, c);
    for (int j = i - 1; j >= 0; j--)
    {
        if (ar[i] == ar[j])
            tot += okdone(j - 1, c - 1) * nCr(find(j, i, ar[i]), k-2);
    }
    return dp[i][c] = tot;
}
void solve()
{
    cin >> n >> k;
    ar = vector<int>(n);
    dp = vector<vector<long long>>(n + 1, vector<long long>(k + 1, -1));
    cnt = vector<vector<long long>>(n + 1, vector<long long>(n + 1, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
        cnt[ar[i]][i]++;
    }
    for (int i = 0; i <= n; i++)
        for (int j = 1; j < n; j++)
            cnt[i][j] += cnt[i][j - 1];

    cout << okdone(n - 1, 2) << "\n";
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<3; j++)
            cout << dp[i][j] << " ";
            cout << "\n";
    }
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    precalc();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}