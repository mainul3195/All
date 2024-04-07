#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int ar[26] = {0};
    for (auto c : s)
        ar[c - 'a']++;
    // for (int i = 0; i < 26; i++)
    //     cout << i << " -> " << ar[i] << "\n";
    char c;
    for (int i = 0; i < 26; i++)
        if (ar[i] == 1)
        {
            c = (char)(i + 'a');
            break;
        }
    // cout << c << "\n";
    for (int i = 0; i < s.size(); i++)
        if (s[i] == c)
        {
            cout << i + 1 << "\n";
            break;
        }
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}