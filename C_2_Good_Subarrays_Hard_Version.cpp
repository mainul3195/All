#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
vector<long long> v, down, ans;
long long n;
int lg[MAXN + 1];
int mnst[MAXN][32], mxst[MAXN][32];
void init()
{
    lg[1] = 0;
    for (int i = 2; i <= MAXN; i++)
        lg[i] = lg[i / 2] + 1;
    for (int i = 1; i <= n; i++)
        mnst[i][0] = v[i];

    for (int j = 1; j <= 30; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            mnst[i][j] = min(mnst[i][j - 1], mnst[i + (1 << (j - 1))][j - 1]);

    for (int i = 1; i <= n; i++)
        mxst[i][0] = v[i];

    for (int j = 1; j <= 30; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            mxst[i][j] = min(mxst[i][j - 1], mxst[i + (1 << (j - 1))][j - 1]);
    return;
}
long long minim(int L, int R)
{
    int j = lg[R - L + 1];
    return min(mnst[L][j], mnst[R - (1 << j) + 1][j]);
}
long long maxim(int L, int R)
{
    int j = lg[R - L + 1];
    return max(mxst[L][j], mnst[R - (1 << j) + 1][j]);
}
void solve()
{
    cin >> n;
    v = vector<long long>(n + 1, 0);
    down = vector<long long>(n + 1);
    ans = vector<long long>(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        down[i - 1] = v[i] - 1;
    }
    ans[0] = 0;
    for (int i = 1; i <= n; i++)
        ans[i] = min(v[i] - 1, ans[i - 1]) + 1;
    long long tot = 0;
    init();
    int q;
    cin >> q;
    while(q--)
    {
        int p, x;
        cin >> p >> x;
        if(x==v[p])
        {
            cout << tot << "\n";
            continue;
        }
        if(x>v[p])
        {
            long long prevdown = x-1;
            long long curans = min(prevdown, ans[p-1]) + 1;
            while(curans>ans[p])
            {
                
            }
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}