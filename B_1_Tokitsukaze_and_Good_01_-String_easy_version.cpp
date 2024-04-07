#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    bool running = 0;
    for (int i = 0; i < n; i++)
    {
        char c = s[i];
        int count = 0;
        while (i < n && s[i] == c)
        {
            count++;
            i++;
        }
        i--;
        if (running)
            ans++;
        if (count & 1)
            running = !running;
    }
    cout << ans << "\n";
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