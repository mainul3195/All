#include <bits/stdc++.h>
using namespace std;
#define lim 100005
int spf[lim];
void make_spf()
{
    for (int i = 2; i < lim; i += 2)
        spf[i] = 2;
    for (int i = 3; i < lim; i += 2)
        if (spf[i] == 0)
            for (int j = i; j < lim; j += 2 * i)
                if (!spf[j])
                    spf[j] = i;
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    make_spf();
    int n, k;
    cin >> n >> k;
    map<vector<pair<int, int>>, int> mp;
    vector<vector<pair<int, int>>> factors;
    long long one_count = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vector<pair<int, int>> v;
        while (x > 1)
        {
            int s = spf[x];
            int count = 0;
            while (x % s == 0)
            {
                x /= s;
                count++;
            }
            count %= k;
            if (count)
                v.push_back({s, count});
        }
        if (v.size() == 0)
            one_count++;
        else
        {
            mp[v]++;
            factors.push_back(v);
        }
    }
    long long ans = 0;
    for (auto vec : factors)
    {
        vector<pair<int, int>> tmp = vec;
        for (auto &[p, c] : tmp)
            c = k - c;
        if (mp.count(tmp))
            ans += mp[tmp];
        if (vec == tmp)
            ans--;
    }
    ans = ans / 2 + one_count * (one_count - 1) / 2;
    cout << ans << "\n";
    return 0;
}