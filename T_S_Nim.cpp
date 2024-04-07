#include <bits/stdc++.h>
using namespace std;
#define lim 10004
vector<int> s;
int grundy[lim], mark[110];
void calc_grundy()
{
    memset(grundy, 0, sizeof(grundy));
    for (int i = 1; i < lim; i++)
    {
        memset(mark, 0, sizeof(mark));
        for (auto j : s)
            if (i - j >= 0)
                mark[grundy[i - j]] = 1;
        int k = 0;
        while (mark[k])
            k++;
        grundy[i] = k;
    }
    return;
}
void solve()
{
    int k;
    while (cin >> k && k)
    {
        s.clear();
        for (int i = 0; i < k; i++)
        {
            int x;
            cin >> x;
            s.push_back(x);
        }
        calc_grundy();
        int m;
        cin >> m;
        while (m--)
        {
            int l;
            cin >> l;
            int Xor = 0;
            while (l--)
            {
                int h;
                cin >> h;
                Xor ^= grundy[h];
            }
            if (Xor)
                cout << "W";
            else
                cout << "L";
        }
        cout << "\n";
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}