#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        cout << "Case " << tc << ": ";
        string a;
        long long b;
        cin >> a >> b;
        if (b < 0)
            b *= -1;
        long long res = 0;
        for (auto c : a)
        {
            if (c != '-')
                res = res * 10 + c - '0';
            res = res % b;
        }
        if (res)
            cout << "not divisible\n";
        else
            cout << "divisible\n";
    }
    return 0;
}