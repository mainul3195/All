#include <bits/stdc++.h>
using namespace std;
#define N 22
int F[4200006];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> vc;
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        F[v] = v;
        vc.push_back(v);
    }
    int lim = 1 << N;
    // cout << lim << "\n";
    for (int i = 0; i < N; i++)
        for (int mask = 0; mask < lim; mask++)
            if ((mask & (1 << i)) && F[mask ^ (1 << i)])
                F[mask] = F[mask ^ (1 << i)];
    for (auto v : vc)
    {
        // cout << ((~v) & (lim - 1)) << "\n";
        if (F[(~v) & (lim - 1)])
            cout << F[(~v) & (lim - 1)] << " ";
        else
            cout << "-1 ";
    }

    return 0;
}