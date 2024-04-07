#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> HASH, POW;
vector<int> BASE = {1231, 1567}, MOD = {1000000000 + 7, 1000000000 + 9};
string s;
pair<long long, long long> initHash(string str)
{
    int len = str.size();
    HASH[0][0] = HASH[1][0] = 0;
    for (int b = 0; b < 2; b++)
    {
        for (int i = 1; i <= len; i++)
        {
            HASH[b][i] = (HASH[b][i - 1] * BASE[b] + (str[i - 1] - 'a' + 1)) % MOD[b];
        }
    }
    return {HASH[0][len], HASH[1][len]};
}

long long getHash(int left, int right, int hsh)
{
    int len = (right - left + 1);
    long long ret = (HASH[hsh][right] - HASH[hsh][left - 1] * POW[hsh][len]) % MOD[hsh];
    if (ret < 0)
        ret += MOD[hsh];
    return ret;
}

pair<long long, long long> getHash(int left, int right)
{
    long long hsh0 = getHash(left, right, 0);
    long long hsh1 = getHash(left, right, 1);

    return {hsh0, hsh1};
}

int main()
{
    cin >> s;
    int lim = s.size() + 5;
    HASH = vector<vector<long long>>(2, vector<long long>(lim + 3));
    POW = vector<vector<long long>>(2, vector<long long>(lim + 3));
    POW[0][0] = POW[1][0] = 1;
    for (int b = 0; b < 2; b++)
    {
        for (int j = 1; j < lim; j++)
        {
            POW[b][j] = (POW[b][j - 1] * BASE[b]) % MOD[b];
        }
    }
    initHash(s);
    // cout << "ok";
    int q;
    cin >> q;
    while (q--)
    {
        int s1, s2;
        cin >> s1 >> s2;
        s1++;
        s2++;
        if (s2 < s1)
            s1 ^= s2 ^= s1 ^= s2;
        // cout << s1 << " " << s2 << " -> \n";
        int ans = 0, l = 0, r = s.size() - s2, mid;
        while (l <= r)
        {
            mid = (l + r) / 2;
            // cout << mid << " - ";
            auto h2 = getHash(s2, s2 + mid);
            auto h1 = getHash(s1, s1 + mid);
            // cout << l << " " << r << " " << h1.first << " " << h1.second << " : " << h2.first << " " << h2.second << "\n";
            if (h1 == h2)
            {
                ans = mid + 1;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        cout << ans << "\n";
    }
    return 0;
}