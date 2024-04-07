#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    vector<int> type(q), a(q, 0), b(q, 0);
    int mx = 0;
    for (int i = 0; i < q; i++)
    {
        cin >> type[i] >> a[i];
        if (type[i] == 2)
            cin >> b[i];
        mx = max({mx, a[i], b[i]});
    }
    vector<int> par(mx + 1), ans;
    for (int i = 0; i < par.size(); i++)
        par[i] = i;
    for (int i = q - 1; i >= 0; i--)
    {
        if (type[i] == 1)
            ans.push_back(par[a[i]]);
        else
            par[a[i]] = par[b[i]];
    }
    reverse(ans.begin(), ans.end());
    for (auto i : ans)
        cout << i << " ";
    cout << "\n";
    return 0;
}