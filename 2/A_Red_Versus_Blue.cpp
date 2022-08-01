#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, r, b;
    cin >> n >> r >> b;
    if (r == b)
    {
        for (int i = 0; i < r; i++)
            cout << "RB";
        cout << "\n";
    }
    else if (r == b + 1)
    {
        for (int i = 0; i < b; i++)
            cout << "RB";
        cout << "R\n";
    }
    else
    {
        int extra = r - b - 1;
        int div = extra / (b + 1);
        int mod = extra % (b + 1);
        string s = "";
        for (int i = 0; i <= div; i++)
            s += "R";
        // cout << extra << " " << div << " " << mod << " " << s << "\n";
        for (int i = 0; i < b; i++)
        {
            cout << s;
            if (mod)
            {
                mod--;
                cout << 'R';
            }
            cout << 'B';
        }
        if (mod)
            cout << s << "R\n";
        else
            cout << s << "\n";
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