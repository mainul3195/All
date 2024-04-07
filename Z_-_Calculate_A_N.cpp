#include <bits/stdc++.h>
using namespace std;
long long B, P, Mod;
long long bigMod(long long b, long long p)
{
    if (!p)
        return 1;
    if (p & 1)
        return (b * bigMod(b, p - 1)) % Mod;
    long long T = bigMod(b, p / 2);
    return (T * T) % Mod;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> B >> P >> Mod)
        cout << bigMod(B % Mod, P) << "\n";
    return 0;
}