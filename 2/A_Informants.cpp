#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    while (cin >> n >> m && (n | m))
    {
        vector<bool> v(n + 1, 1);
        while (m--)
        {
            int a, b;
            cin >> a >> b;
            if (b < 0 && v[-b])
            {
                n--;
                v[-b] = 0;
            }
        }
        cout << n << "\n";
    }
    return 0;
}