#include <bits/stdc++.h>
using namespace std;
#define lim 5000006
vector<long long> base = {1231, 1567}, mod = {1000000000 + 7, 1000000000 + 9}, ans;
pair<long long, long long> Forward, Backward;
vector<vector<long long>> Pow(2, vector<long long>(lim + 1));
string s;
int n;
void init()
{
    Pow[0][0] = Pow[1][0] = 1;
    for (int i = 0; i < 2; i++)
        for (int j = 1; j <= lim; j++)
            Pow[i][j] = (Pow[i][j - 1] * base[i]) % mod[i];
    Forward = Backward = {0, 0};
    return;
}
void update(int i)
{
    Forward.first = (Forward.first * base[0] + s[i] - '0') % mod[0];
    Forward.second = (Forward.second * base[1] + s[i] - '0') % mod[1];
    Backward.first = ((s[i] - '0') * Pow[0][i] + Backward.first) % mod[0];
    Backward.second = ((s[i] - '0') * Pow[1][i] + Backward.second) % mod[1];
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    cin >> s;
    n = s.size();
    ans = vector<long long>(n + 1, 0);
    long long tot = 0;
    for (int i = 1; i <= n; i++)
    {
        update(i - 1);
        // cout << Forward.first << " " << Forward.second << " " << Backward.first << " " << Backward.second << "\n";
        if (Forward == Backward)
        {
            ans[i] = ans[i / 2] + 1;
            tot += ans[i];
        }
    }
    cout << tot << "\n";
    return 0;
}