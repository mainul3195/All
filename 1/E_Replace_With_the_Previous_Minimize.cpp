#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, k;
    string s;
    cin >> n >> k >> s;
    map<char, char> mp;
    for (int i = 0; i < 26; i++)
        mp[i + 'a'] = i + 'a';
    int count = 0;
    for (char c : s)
    {
        char tmp = c;
        while (count < k && mp[tmp] != 'a')
        {
            tmp--;
            count++;
        }
        for (char tmp2 = tmp; tmp2 <= c; tmp2++)
            mp[tmp2] = mp[tmp];
        if (count == k)
            break;
    }
    for (auto i : s)
        cout << mp[i];
    cout << "\n";
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