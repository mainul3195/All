#include <bits/stdc++.h>
using namespace std;
// returns 0 base index of first found in text or -1
long long matchString(const string &text, const string &pattern)
{
    if (text.size() < pattern.size())
        return -1;
    vector<long long> isp(pattern.size(), -1);
    long long l = -1, r = 1;
    while (r < pattern.size())
    {
        if (pattern[l + 1] == pattern[r])
            isp[r++] = ++l;
        else
        {
            if (!l)
                l = -1;
            else if (l > 0)
                l = isp[l - 1];
            else
                r++;
        }
    }
    for (auto i : isp)
        cout << i << " ";
    return 0;
    l = -1, r = 0;
    while (r < text.size() && l != pattern.size() - 1)
    {
        if (pattern[l + 1] == text[r])
            r++, l++;
        else
            l >= 0 ? l = isp[l] : r++;
    }
    return l == pattern.size() - 1 ? r - pattern.size() : -1;
}
void solve()
{
    // int n;
    // string s;
    // cin >> n >> s;
    // string pattern;
    // int first_one = -1;
    // for (int i = 0; i < n; i++)
    //     if (s[i] == '0')
    //     {
    //         for (; i < n; i++)
    //         {
    //             if (s[i] == '0')
    //                 pattern.push_back('1');
    //             else
    //                 pattern.push_back('0');
    //         }
    //     }
    // cout << pattern << "\n";
    string s = "100011010100101";
    string pattern = "10100111";
    matchString(s, pattern);
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}