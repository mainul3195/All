#include <bits/stdc++.h>
using namespace std;
int mark[30];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while (cin >> n && n)
    {
        memset(mark, 0, sizeof(mark));
        while (n--)
        {
            int x;
            cin >> x;
            int pos = 0;
            while (x)
            {
                if (x & 1)
                    mark[pos]++;
                pos++;
                x >>= 1;
            }
        }
        int ans = 0;
        for (int i = 25; i >= 0; i--)
            if (mark[i] & 1)
            {
                ans = mark[i];
                break;
            }
        cout << ans << "\n";
    }
    return 0;
}