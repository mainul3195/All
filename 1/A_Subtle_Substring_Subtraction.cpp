#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    if (s.size() == 1)
    {
        cout << "Bob " << s[0] - 'a' + 1 << "\n";
        return;
    }
    cout << "Alice ";
    int tot = 0, minant = 0;
    if (s.size() & 1)
    {
        if (s[0] > s[s.size() - 1])
        {
            minant = s[s.size() - 1] - 'a' + 1;
            for (int i = 0; i < s.size() - 1; i++)
                tot += s[i] - 'a' + 1;
        }
        else
        {
            minant = s[0] - 'a' + 1;
            for (int i = 1; i < s.size(); i++)
                tot += s[i] - 'a' + 1;
        }
    }
    else
        for (char i : s)
            tot += i - 'a' + 1;
    cout << tot - minant << "\n";

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