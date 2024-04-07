#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    vector<int> ones, zeroes, track(n);
    for (auto &i : track)
        cin >> i;
    for (int i = 0; i < n; i++)
    {
        int nm;
        cin >> nm;
        if (track[i])
            ones.push_back(nm);
        else
            zeroes.push_back(nm);
    }
    sort(ones.rbegin(), ones.rend());
    sort(zeroes.rbegin(), zeroes.rend());
    if (ones.size() == zeroes.size())
    {
        for (auto &i : ones)
            i <<= 1;
        for (auto &i : zeroes)
            i <<= 1;
        if (ones.back() < zeroes.back())
            ones[ones.size() - 1] = ones.back() / 2;
        else
            zeroes[zeroes.size() - 1] = zeroes.back() / 2;
    }
    else
    {
        int mn = min(ones.size(), zeroes.size());
        for (int i = 0; i < mn; i++)
            ones[i] <<= 1;
        for (int i = 0; i < mn; i++)
            zeroes[i] <<= 1;
    }
    int tot = 0;
    for (auto i : ones)
        tot += i;
    for (auto i : zeroes)
        tot += i;
    cout << tot << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}