#include <bits/stdc++.h>
using namespace std;
int n, k;
string s;
vector<int> avail;
void make_short(string &s)
{
    avail = vector<int>(26, 0);
    string tmp = "";
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        tmp.push_back(s[i]);
        while (i < s.size() && s[i] == c)
            i++;
        i--;
    }
    s = tmp;
    for (auto c : s)
        avail[c - 'a']++;
    return;
}
void erase(char c)
{
    string tmp = "";
    for (auto i : s)
        if (i != c)
            tmp.push_back(i);
    s = tmp;
    return;
}
void solve()
{
    cin >> n >> k >> s;
    int ans = 0;
    while (s.size())
    {
        make_short(s);
        int min_ind = -1;
        int min_val = 10000000;
        for (int i = 0; i < 26; i++)
            if (avail[i])
            {
                if (avail[i] < min_val)
                {
                    min_val = avail[i];
                    min_ind = i;
                }
            }
        ans += min_val;
        erase((char)(min_ind + 'a'));
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