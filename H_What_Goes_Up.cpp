#include <bits/stdc++.h>
using namespace std;
vector<long long> v, ans, increasing;
vector<int> par, indexes;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while (cin >> n)
        v.push_back(n);
    par = vector<int>(v.size(), -1);
    increasing.push_back(v[0]);
    indexes.push_back(0);
    for (int i = 1; i < v.size(); i++)
    {
        int ind = lower_bound(increasing.begin(), increasing.end(), v[i]) - increasing.begin();
        if (ind == increasing.size())
        {
            increasing.push_back(v[i]);
            par[i] = indexes.back();
            indexes.push_back(i);
        }
        else
        {
            increasing[ind] = v[i];
            indexes[ind] = i;
            if (ind)
                par[i] = indexes[ind - 1];
        }
    }
    cout << increasing.size() << "\n-\n";
    int cur = indexes.back();
    while (1)
    {
        ans.push_back(v[cur]);
        if (par[cur] == -1)
            break;
        cur = par[cur];
    }
    while (ans.size())
    {
        cout << ans.back() << "\n";
        ans.pop_back();
    }

    return 0;
}