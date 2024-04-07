#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    string cont = "";
    int found[26] = {0}, i;
    for (i = 0; i < s.size() && !found[s[i] - 'a']; i++)
    {
        cont.push_back(s[i]);
        found[s[i] - 'a'] = 1;
    }
    bool ok = 1;
    for (; i + cont.size() <= s.size(); i += cont.size())
        if (s.substr(i, cont.size()) != cont)
        {
            ok = !ok;
            break;
        }
    // cout << "First -> " << i << " " << ok << "\n";
    if (ok && i < s.size())
    {
        for (int j = 0; i < s.size(); i++, j++)
            if (s[i] != cont[j])
            {
                ok = !ok;
                break;
            }
    }
    // cout << "second -> " << i << " " << ok << "\n";

    if (ok)
        cout << "YES\n";
    else
        cout << "NO\n";
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