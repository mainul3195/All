#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    if (!(n - k))
        cout << "-1\n";
    else
    {
        if ((n - k) % 2)
        {
            for (int i = 1; i <= k + 1; i++)
                cout << i << " ";
            for (int i = k + 2; i <= n; i += 2)
                cout << i + 1 << " " << i << " ";
        }
        else
        {
            cout << n << " ";
            for (int i = 2; i <= k + 1; i++)
                cout << i << " ";
            for (int i = k + 3; i <= n; i += 2)
                cout << i << " " << i - 1 << " ";
            cout << 1 << "\n";
        }
    }
    return 0;
}