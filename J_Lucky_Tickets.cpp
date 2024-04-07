#include <bits/stdc++.h>
using namespace std;
int n, s;
string dp[51][501];
string sum(string a, string b)
{
    string c;
    int carry = 0;
    int lim = max(a.size(), b.size());
    for (int i = 0; i < lim || carry; i++)
    {
        int sum = 0;
        int v1 = i < a.size() ? a[i] - '0' : 0;
        int v2 = i < b.size() ? b[i] - '0' : 0;
        sum = v1 + v2 + carry;
        c.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    return c;
}
string mul(string a, string b)
{
    string c;
    for (int i = 0; i < b.size(); i++)
    {
        int carry = 0;
        for (int j = 0; j < a.size() || carry; j++)
        {
            int pos = (i + j);
            int v1 = b[i] - '0';
            int v2 = j < a.size() ? a[j] - '0' : 0;
            int v3;
            if (pos < c.size())
                v3 = c[pos] - '0';
            else
            {
                v3 = 0;
                c.push_back('0');
            }
            int mul = v1 * v2 + carry + v3;
            c[pos] = mul % 10 + '0';
            carry = mul / 10;
        }
    }
    return c;
}

string okdone(int i = 0, int rem = s / 2)
{
    if (i == n)
        return (rem ? "0" : "1");
    if (dp[i][rem] != "-1")
        return dp[i][rem];
    string tot = "0";
    int lim = min(9, rem);
    for (int j = 0; j <= lim; j++)
        tot = sum(tot, okdone(i + 1, rem - j));
    return dp[i][rem] = tot;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    if (s & 1)
        cout << "0\n";
    else
    {
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= s / 2; j++)
                dp[i][j] = "-1";
        string tmp = okdone();
        tmp = mul(tmp, tmp);
        reverse(tmp.begin(), tmp.end());
        cout << tmp << "\n";
    }
    return 0;
}