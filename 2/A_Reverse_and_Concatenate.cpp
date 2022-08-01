#include <bits/stdc++.h>
using namespace std;
bool pallindrome(string &s)
{
    int i = 0, j = s.size() - 1;
    for (; i < j; i++, j--)
        if (s[i] != s[j])
            return false;
    return true;
}
void solve()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    if (pallindrome(s) || !k)
        cout << 1 << "\n";
    else
        cout << "2\n";
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