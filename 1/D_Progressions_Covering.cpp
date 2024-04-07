#include <bits/stdc++.h>
using namespace std;
long long n, k;
vector<long long> b;
void solve()
{
    cin >> n >> k;
    b = vector<long long>(n);
    for (auto &i : b)
        cin >> i;
    long long decrease = 0, minant = 0;
    vector<long long> ends(n, 0);
    long long ans = 0;
    for (long long i = n - 1; i >= 0; i--)
    {
        decrease -= minant;
        long long dif = b[i] - decrease;
        // cout << dif << "\n";
        // cout << " \ni -> " << i << "\n"
        //      << decrease << " " << minant << " " << dif << "\n";
        if (dif > 0)
        {
            long long can_add = min(i + 1, k);
            long long no_of_progression = (dif + can_add - 1) / can_add;
            // cout << "\t" << can_add << " " << no_of_progression << "\n";
            ans += no_of_progression;
            minant += no_of_progression;
            ends[i - can_add + 1] -= no_of_progression;
            decrease += no_of_progression * can_add;
        }
        minant += ends[i];
        decrease += ends[i];
        // for (auto nm : ends)
        //     cout << nm << " ";
        // cout << "\n";
        // break;
    }
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