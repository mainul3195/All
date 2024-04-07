#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int ec = 0, oc = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a & 1)
            oc++;
        else
            ec++;
    }
    if (n & 1)
    {
        if ((n + 1) % 4 == 0)
        {
            if (ec % 4 == 0 || (ec + 1) % 4 == 0)
                cout << "Alice\n";
            else
                cout << "Bob\n";
        }
        else
        {
            if (ec % 4 == 0 || (ec + 1) % 4 == 0)
                cout << "Bob\n";
            else
                cout << "Alice\n";
        }
    }
    else
    {
        if (n % 4 == 0)
        {
            if ((ec - 2) % 4 == 0)
                cout << "Bob\n";
            else
                cout << "Alice\n";
        }
        else
        {
            if (ec % 4 == 0)
                cout << "Bob\n";
            else
                cout << "Alice\n";
        }
    }
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