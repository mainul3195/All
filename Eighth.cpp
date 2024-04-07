#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    if (s == "P=NP")
    {
        cout << "skipped\n";
        return;
    }
    int a, b;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '+')
        {
            a = stoi(s.substr(0, i));
            b = stoi(s.substr(i + 1, s.size() - i - 1));
            cout << a + b << "\n";
        }
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