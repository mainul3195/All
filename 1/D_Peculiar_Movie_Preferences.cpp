#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (auto &i : v)
        cin >> i;
    int trie2[28][28] = {0}, trie3[28][28][28] = {0};
    for(auto s: v)
    {
        if(s.size()==1)
        {
            cout << "YES\n";
            return;
        }
        int a, b, c;
        if(s.size()==2)
        {
            a = s[0] - 'a' + 1;
            b = s[1] - 'a' + 1;
            trie2[a][b]++;
        }
        if (s.size() == 3)
        {
            a = s[0] - 'a' + 1;
            b = s[1] - 'a' + 1;
            c = s[2] - 'a' + 1;
            trie3[0][b][c]++;
            trie3[a][b][c]++;
        }
    }
    for(auto s: v)
    {
        int a, b, c;
        if (s.size() == 2)
        {
            a = s[0] - 'a' + 1;
            b = s[1] - 'a' + 1;
            if(trie2[b][a] || trie3[0][b][a])
            {
                cout << "YES\n";
                return;
            }
            trie2[a][b]--;
        }
        if (s.size() == 3)
        {
            a = s[0] - 'a' + 1;
            b = s[1] - 'a' + 1;
            c = s[2] - 'a' + 1;
            if (trie3[c][b][a] || trie2[b][a])
            {
                cout << "YES\n";
                return;
            }
            trie3[0][b][c]--;
            trie3[a][b][c]--;
        }
    }
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