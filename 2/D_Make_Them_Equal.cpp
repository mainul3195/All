// #include <bits/stdc++.h>
// using namespace std;
// vector<int> p2, lg2(10000);
// void solve()
// {
//     int n, k;
//     cin >> n >> k;
//     vector<long long> b(n), c(n), r(n);
//     for (auto &i : b)
//         cin >> i;
//     for (auto &i : c)
//         cin >> i;
//     int tot = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int nm = b[i];
//         int s = 1, count = 0;
//         while (s < nm)
//         {
//             count++;
//             int r = max(1, s / (nm - s));
//             if (s / r <= nm - s)
//                 s += s / r;
//             else
//                 s += lg2[nm - s];
//         }
//         tot += r[i] = count;
//     }
//     int mn = min(tot, k);
//     vector<long long> dp(mn + 1);
//     for (auto &i : dp)
//         i = -1;
//     dp[0] = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = mn; j >= r[i]; j--)
//             dp[j] = max(dp[j], dp[j - r[i]] != -1 ? dp[j - r[i]] + c[i] : -1);
//     }

//     long long mx = 0;
//     for (auto i : dp)
//         mx = max(mx, i);
//     cout << mx << "\n";
//     return;
// }
// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     int ml = 1;
//     while (ml < 10000)
//     {
//         p2.push_back(ml);
//         ml <<= 1;
//     }
//     for (int i = 0; p2[i] <= 1000; i++)
//         for (int j = p2[i]; j < p2[i + 1]; j++)
//             lg2[j] = p2[i];

//     int t;
//     cin >> t;
//     while (t--)
//         solve();
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
vector<int> mv(1009);
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<long long> b(n), c(n), r(n);
    for (auto &i : b)
        cin >> i;
    for (auto &i : c)
        cin >> i;
    int tot = 0;
    for (int i = 0; i < n; i++)
        tot += r[i] = mv[b[i]];
    int mn = min(tot, k);
    vector<long long> dp(mn + 1);
    for (auto &i : dp)
        i = -1;
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = mn; j >= r[i]; j--)
            dp[j] = max(dp[j], dp[j - r[i]] != -1 ? dp[j - r[i]] + c[i] : -1);
    }

    long long mx = 0;
    for (auto i : dp)
        mx = max(mx, i);
    cout << mx << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 2; i <= 1000; i++)
        mv[i] = 2000000000;
    for (int i = 1; i <= 1000; i++)
        for (int j = 1; j <= i; j++)
            if (i + i / j <= 1000)
                mv[i + i / j] = min(mv[i + i / j], mv[i] + 1);
    // for (int i = 1; i <= 16; i++)
    //     cout << mv[i] << "\n";

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}