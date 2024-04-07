// #include <bits/stdc++.h>
// using namespace std;

// void solve()
// {
//     long long n;
//     cin >> n;
//     long long ans = (1LL << ((int)log2(n + .5)));
//     cout << ans << "\n";
//     return;
// }
// int32_t main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     int t;
//     cin >> t;
//     while (t--)
//         solve();
//     return 0;
// }

#include <stdio.h>
int main()
{
    long long int t;
    scanf("%lld", &t);
    while (t--)
    {
        long long int n, d, k, p;
        scanf("%lld", &n);
        long long int s[n];
        for (long long int i = 0; i < n; i++)
            s[i] = i + 1;
        for (long long int i = 0; i < n; i++)
        {
            int temp = 0;
            d = (i + 1);
            k = (i + 1) * 2;
            if (k <= n)
            {
                temp = s[d - 1];
                s[d - 1] = s[k - 1];
                s[k - 1] = temp;
            }
        }
        for (long long int i = 0; i < n; i++)
            if (s[i] == 1)
            {
                p = i + 1;
                break;
            }
        printf("%lld\n", p);
    }
    return 0;
}
