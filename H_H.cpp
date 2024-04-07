#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int rank = 1, tot = 0;
    for (auto c : s)
    {
        if (c == 'c')
            cout << "No\n";
        else if (c == 'a')
        {
            if (tot < a + b)
            {
                cout << "Yes\n";
                tot++;
            }
            else
                cout << "No\n";
        }
        else
        {
            if (tot < a + b && rank <= b)
            {
                cout << "Yes\n";
                tot++;
                rank++;
            }
            else
                cout << "No\n";
        }
    }

    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}