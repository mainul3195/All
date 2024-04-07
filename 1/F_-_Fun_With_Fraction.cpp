#include <bits/stdc++.h>
using namespace std;
string n, d, ans, rem;
bool neg;
char dv;
map<string, int> mp;
void divide(string, string);
void neg_handle();
void init();
string mul(string a, int n);
int cmp(string a, string b);
void solve()
{
    init();
    neg_handle();
    string hor, lob, remainder;
    hor = d;
    for (int i = 0; i < n.size(); i++)
    {
        lob += n[i];
        divide(lob, hor);
        ans.push_back(dv);
        lob = rem;
    }
    int count = 0;
    if (lob.size())
    {
        ans.push_back('.');
        mp[lob] = ans.size();
        while (lob.size())
        {
            lob += '0';
            divide(lob, hor);
            ans.push_back(dv);
            lob = rem;
            if (mp.count(lob))
            {
                int ind = mp[lob];
                ans.push_back('0');
                for (int i = ans.size() - 1; i > ind; i--)
                    swap(ans[i], ans[i - 1]);
                ans[ind] = '(';
                ans.push_back(')');
                break;
            }
            if (++count >= 1000)
                break;
        }
    }
    reverse(ans.begin(), ans.end());
    while (ans.back() == '0')
        ans.pop_back();
    if (ans.back() == '.')
        ans.push_back('0');
    reverse(ans.begin(), ans.end());
    if (ans.size())
    {
        if (neg)
            cout << "-";
        cout << ans;
        if (count >= 1000)
            cout << "...";
        cout << "\n";
    }
    else
        cout << "0\n";

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}

int cmp(string a, string b)
{
    /*
    a>b -> 1
    a<b -> -1
    a=b -> 0
    */
    if (a.size() < b.size())
        return -1;
    if (a.size() > b.size())
        return 1;
    for (int i = 0; i < a.size(); i++)
        if (a[i] != b[i])
        {
            if (a[i] > b[i])
                return 1;
            return -1;
        }
    return 0;
}
string mul(string a, int n)
{
    string ans;
    int carry = 0;
    while (a.size() || carry)
    {
        int tot = (a.size() ? (a.back() - '0') * n : 0) + carry;
        ans.push_back(tot % 10 + '0');
        carry = tot / 10;
        if (a.size())
            a.pop_back();
    }
    while (ans.back() == '0')
        ans.pop_back();
    reverse(ans.begin(), ans.end());
    return ans;
}
string substract(string a, string b)
{
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string ans;
    int carry = 0;
    for (int i = 0; i < a.size(); i++)
    {
        int upor = a[i] - '0';
        int nich = (i < b.size() ? b[i] - '0' : 0) + carry;
        if (upor < nich)
        {
            upor += 10;
            carry = 1;
        }
        else
            carry = 0;
        ans.push_back(upor - nich + '0');
    }
    while (ans.back() == '0')
        ans.pop_back();
    reverse(ans.begin(), ans.end());
    return ans;
}
void divide(string a, string b)
{
    int i;
    for (i = 0; i <= 9; i++)
    {
        if (cmp(a, mul(b, i)) < 0)
            break;
    }
    dv = i - 1 + '0';
    rem = substract(a, mul(b, i - 1));
    return;
}
void init()
{
    cin >> n >> d;
    ans.clear();
    mp.clear();
}
void neg_handle()
{
    neg = (n[0] == '-') ^ (d[0] == '-');
    if (n[0] == '-')
    {
        reverse(n.begin(), n.end());
        n.pop_back();
        reverse(n.begin(), n.end());
    }
    if (d[0] == '-')
    {
        reverse(d.begin(), d.end());
        d.pop_back();
        reverse(d.begin(), d.end());
    }
    return;
}
