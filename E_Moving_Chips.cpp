#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<int> up, down, add(n, 0);
    int prev = 3;
    int l = -1, r = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == '*' || b[i] == '*')
        {
            if (l == -1)
                l = i;
            r = i;
        }
        if (a[i] == '*' && b[i] == '*')
            add[i] = 1;
        else if (a[i] == '*')
        {
            if (prev == 0)
            {
                for (auto ind : down)
                    add[ind]++;
                down.clear();
                up.clear();
                up.push_back(i);
            }
            else
            {
                prev = 0;
                up.push_back(i);
            }
        }
        else if (b[i] == '*')
        {
            if (prev == 1)
            {
                for (auto ind : up)
                    add[ind]++;
                down.clear();
                up.clear();
                down.push_back(i);
                prev = 1;
            }
            else
            {
                prev = 1;
                down.push_back(i);
            }
        }
    }
    if (up.size() > down.size())
    {
        for (auto ind : down)
            add[ind]++;
    }
    else
        for (auto ind : up)
            add[ind]++;
    int tot = 0;
    for (auto i : add)
    {
        // cout << i << " ";
        tot += i;
    }
    // cout << "\n";
    cout << r - l + tot << "\n";

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