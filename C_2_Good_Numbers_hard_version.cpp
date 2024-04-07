#include <bits/stdc++.h>
using namespace std;
vector<long long> pow3;
void solve()
{
    long long n;
    cin >> n;
    vector<int> bin(39, 0);
    int i = 0;
    for (auto p : pow3)
    {
        if (n >= p)
        {
            bin[i] = 1;
            n -= p;
        }
        i++;
    }
    if (n)
        for (int i = bin.size() - 1; i >= 0; i--)
        {
            if (bin[i] == 0)
            {
                bin[i] = 1;
                break;
            }
            else
                bin[i] = 0;
        }
    long long ans = 0;
    for (int i = 38; i >= 0; i--)
        ans += bin[i] * pow3[i];
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long mx = 2000000000000000000;
    long long ml = 1;
    while (ml <= mx)
    {
        pow3.push_back(ml);
        ml *= 3;
    }
    reverse(pow3.begin(), pow3.end());
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}