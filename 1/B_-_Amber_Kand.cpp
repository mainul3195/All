#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string a, b;
    cin >> a >> b;
    string c = a, d = b;
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());

    if (c != d)
    {
        cout << "No\n";
        return;
    }

    string s1 = "", s2 = "", j1 = "", j2 = "";
    for (auto c : a)
    {
        if (c % 2)
            s1.push_back(c);
        else
            j1.push_back(c);
    }
    for (auto c : b)
    {
        if (c % 2)
            s2.push_back(c);
        else
            j2.push_back(c);
    }
    if (s1 == s2 && j1 == j2)
        cout << "Yes\n";
    else
        cout << "No\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}