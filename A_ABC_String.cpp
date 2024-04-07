#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    if (s[0] == s[s.size() - 1])
    {
        cout << "NO\n";
        return;
    }
    int a = 0, b = 0, c = 0;
    for (auto i : s)
    {
        if (i == 'A')
            a++;
        else if (i == 'B')
            b++;
        else
            c++;
    }
    map<char, char> mp;
    if (a == b + c)
    {
        if (s[0] == 'A')
        {
            mp['A'] = '(';
            mp['B'] = mp['C'] = ')';
        }
        else if (s[s.size() - 1] == 'A')
        {
            mp['A'] = ')';
            mp['B'] = mp['C'] = '(';
        }
    }
    else if(b==c+a)
    {
        if (s[0] == 'B')
        {
            mp['B'] = '(';
            mp['A'] = mp['C'] = ')';
        }
        else if (s[s.size() - 1] == 'B')
        {
            mp['B'] = ')';
            mp['A'] = mp['C'] = '(';
        }
    }
    else if(c==a+b)
    {
        if (s[0] == 'C')
        {
            mp['C'] = '(';
            mp['A'] = mp['B'] = ')';
        }
        else if (s[s.size() - 1] == 'C')
        {
            mp['C'] = ')';
            mp['A'] = mp['B'] = '(';
        }
    }
    else 
    {
        cout << "NO\n";
        return;
    }
    for (auto &i : s)
        i = mp[i];
    int open = 0, close = 0;
    for (auto i : s)
    {
        if (i == '(')
            open++;
        else
            close++;
        if (close > open)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

/*
gcd
lcm
modfact
fact
pfsingle
pfmultiple
ncrsingle
ncrmod
bgmod
mdinverse
sieve
SegmentTree
kmp
bit
sparseTable
vll
pi
ll
Pair
all
mll
mii
mis
msi
vvi
vi
pb
inf
linf
*/