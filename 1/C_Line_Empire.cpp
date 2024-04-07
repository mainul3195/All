#include <bits/stdc++.h>
using namespace std;
long long n, a, b;
vector<long long> pos;
void solve()
{
    cin >> n >> a >> b;
    pos = vector<long long>(n);
    for (auto &i : pos)
        cin >> i;
    long long cur = 0;
    long long tot = b * pos[0];
    //cout << tot << "\n";
    for (int i = 0; i < n - 1; i++)
    {
        int remain = n - i - 1;
        if (remain * b > a)
        {
            tot += a * (pos[i] - cur);
            cur = pos[i];
        }
        tot += b * (pos[i + 1] - cur);
        //cout << "i = " << i << " \t remain = " << remain << " \t cur = " << cur << "\n";
    }
    cout << tot << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}