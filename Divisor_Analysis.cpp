#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long phi_mod_1;
long long bigMod(long long b, long long p, long long M)
{
    if (!p)
        return 1;
    long long tmp = bigMod(b, p / 2, M);
    tmp = tmp * tmp % M;
    if (p & 1)
        tmp = tmp * b % M;
    return tmp;
}
void solve()
{
    int n;
    cin >> n;
    long long sum = 1, nod = 1, pod = 1, prd = 1, nod_mod_1 = 1;
    vector<pair<long long, long long>> Pair;
    bool sq = 1;
    long long sq_val = 1;
    while (n--)
    {
        long long pr, po;
        cin >> pr >> po;
        if (po & 1)
            sq = 0;
        sq_val = sq_val * bigMod(pr, po / 2, mod) % mod;
        prd = prd * bigMod(pr, po, mod) % mod;
        nod = (nod * (po + 1)) % mod;
        nod_mod_1 = (nod_mod_1 * (po + 1)) % (mod - 1);
        sum = (sum * (bigMod(pr, po + 1, mod) - 1) % mod * bigMod(pr - 1, mod - 2, mod)) % mod;
    }
    cout << prd << " " << nod << " " << nod_mod_1 << "\n";
    cout << phi_mod_1 << "\n";
    cout << (nod_mod_1 * bigMod(2, phi_mod_1 - 1, mod - 1) % (mod - 1)) << "\n";
    prd = bigMod(prd, (nod_mod_1 + 1) * bigMod(2, phi_mod_1 - 1, mod - 1) % (mod - 1), mod);
    // if (sq)
    //     prd = prd * bigMod(sq_val, mod - 2, mod) % mod;
    cout << nod << " " << sum << " " << prd << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    phi_mod_1 = mod - 1;
    int n = phi_mod_1;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            phi_mod_1 -= phi_mod_1 / i;
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        phi_mod_1 -= phi_mod_1 / n;
    solve();
    return 0;
}