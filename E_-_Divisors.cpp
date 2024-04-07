#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
struct nd
{
    long long nm;
    vector<pair<long long, int>> factors;
    bool done;
    nd()
    {
        done = 0;
    }
};
long long isSquare(long long x)
{
    long long s = sqrt(x + .5);
    return s * s == x;
}
long long isCube(long long x)
{
    long long s = cbrt(x + .5);
    return s * s * s == x;
}
long long is4throot(long long x)
{
    long long s1 = sqrt(x + .5);
    long long s2 = sqrt(s1 + .5);
    return s2 * s2 * s2 * s2 == x;
}
void solve()
{
    int n;
    cin >> n;
    vector<nd> v(n);
    for (auto &i : v)
        cin >> i.nm;
    for (auto &i : v)
    {
        i.done = 1;
        if (is4throot(i.nm))
            i.factors.push_back({sqrt(.2 + sqrt(i.nm + .5)), 4});
        else if (isSquare(i.nm))
            i.factors.push_back({sqrt(i.nm + .5), 2});
        else if (isCube(i.nm))
            i.factors.push_back({cbrt(i.nm + .5), 3});

        else
            i.done = 0;
    }
    for (int i = 0; i < n; i++)
        if (!v[i].done)
            for (int j = 0; j < n; j++)
                if (i != j)
                {
                    long long g = __gcd(v[i].nm, v[j].nm);
                    if (g != 1)
                    {
                        if (!v[i].done && g != v[i].nm)
                        {
                            v[i].factors.push_back({g, 1});
                            v[i].factors.push_back({v[i].nm / g, 1});
                            v[i].done = 1;
                        }
                        if (!v[j].done && g != v[j].nm)
                        {
                            v[j].factors.push_back({g, 1});
                            v[j].factors.push_back({v[j].nm / g, 1});
                            v[j].done = 1;
                        }
                    }
                }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << " -> \n";
    //     cout << v[i].nm << " " << v[i].done << "\n";
    //     for (auto [a, b] : v[i].factors)
    //         cout << a << " - " << b << "\n";
    //     cout << "\n";
    // }
    map<long long, long long> mp;
    for (auto i : v)
        for (auto [f, t] : i.factors)
            mp[f] += t;
    long long ans = 1;
    for (auto [_, p] : mp)
        ans = ans * (p + 1) % mod;
    map<long long, long long> vejailla;
    for (auto i : v)
        if (!i.done)
            vejailla[i.nm]++;
    for (auto [_, p] : vejailla)
        ans = ans * (p + 1) * (p + 1) % mod;
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}