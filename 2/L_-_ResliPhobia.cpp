#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    int ar[n];
    for (int i = 0; i < n; i++)
        cin >> ar[i];

    int start, end;
    long long tot = 0;
    for (int i = 0; i < n; i++)
    {
        start = i;
        int parity = ar[i] & 1;
        while (i < n && (ar[i] & 1) == parity)
            i++;
        end = --i;
        sort(ar + start, ar + end + 1);
        for (int j = end; j >= start && end - j + 1 <= k; j--)
            tot += ar[j];
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