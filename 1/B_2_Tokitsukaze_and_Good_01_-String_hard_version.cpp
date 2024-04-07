#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int count = 0;
    for (int i = 0; i < n; i += 2)
        if (s[i] != s[i + 1])
        {
            if (i > 0)
            {
                if (s[i - 1] == '0')
                    s[i] = s[i + 1] = '0';
                else
                    s[i] = s[i + 1] = '1';
            }
            else if (i < n - 2)
            {
                if (s[i + 2] == '0')
                    s[i] = s[i + 1] = '0';
                else
                    s[i] = s[i + 1] = '1';
            }
            else
                s[i] = s[i + 1] = '0';
            count++;
        }
    // cout << s << "\n";
    int cont_sg = 0;
    for (int i = 0; i < n; i++)
    {
        char c = s[i];
        while (i < n && s[i] == c)
            i++;
        i--;
        cont_sg++;
    }
    cout << count << " " << cont_sg << "\n";
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