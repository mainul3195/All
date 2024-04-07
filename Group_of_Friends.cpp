#include <bits/stdc++.h>
using namespace std;
#define lim 1000005
vector<long long> spf(lim + 1);
int par[100005], found[100005];
void smallest_pf()
{
    for (long long i = 2; i <= lim; i += 2)
        spf[i] = 2;
    for (long long i = 3; i * i <= lim; i += 2)
        if (!spf[i])
            for (long long j = i; j <= lim; j += 2 * i)
                if (!spf[j])
                    spf[j] = i;
    for (int i = 3; i <= lim; i += 2)
        if (!spf[i])
            spf[i] = i;
    return;
}
int getpar(int u)
{
    if (par[u] == u)
        return u;
    return par[u] = getpar(par[u]);
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < 100005; i++)
        par[i] = i;
    for (int i = 0; i < n; i++)
    {
        vector<int> prime_factors;
        int x;
        cin >> x;
        while (x > 1)
        {
            int pf = spf[x];
            while (x % pf == 0)
                x /= pf;
            prime_factors.push_back(pf);
            found[prime_factors[0]] = 1;
            for (int j = 1; j < prime_factors.size(); j++)
            {
                found[prime_factors[j]] = 1;
                int u = prime_factors[j - 1];
                int v = prime_factors[j];
                int pu = getpar(u);
                int pv = getpar(v);
                if (pu != pv)
                    par[pu] = pv;
            }
        }
    }
    set<int> st;
    for (int i = 1; i <= 100000; i++)
        if (found[i])
            st.insert(getpar(i));
    cout << st.size() << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    smallest_pf();
    solve();
    return 0;
}