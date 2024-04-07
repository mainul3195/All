#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int t, n, i, j;

    scanf("%lld", &t);

    while (t--)
    {
        scanf("%lld", &n);
        vector<pair<long long int, long long int>> pr(n);

        for (i = 0; i < n; i++)
        {
            scanf("%lld %lld", &pr[i].first, &pr[i].second);
        }

        sort(pr.begin(), pr.end());

        for (i = 0; i < n - 1; i++)
        {
            if (pr[i].first == pr[i + 1].first && pr[i].second < pr[i + 1].second)
            {
                swap(pr[i], pr[i + 1]);
            }
        }
        for (i = 0; i < n; i++)
        {
            printf("%lld %lld\n", pr[i].first, pr[i].second);
        }
    }

    return 0;
}