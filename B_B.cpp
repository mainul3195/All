#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    vector<int> filled(n + 1, 1), ans(n * n + 1), low(n + 1, n * n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i - 1].first;
        v[i - 1].second = i;
    }
    sort(v.begin(), v.end());
    int blocked = 0;
    for (auto [pos, val] : v)
    {
        int available = pos - blocked;
        if (available >= val)
        {
            ans[pos] = val;
            blocked += val;
        }
        else
        {
            cout << "No\n";
            return;
        }
    }
    int last = n * n;
    queue<pair<int, int>> q;
    int val, remaining = 0;
    vector<int> serial;
    for (int i = 1; i <= last; i++)
        if (ans[i])
            serial.push_back(ans[i]);
    int cur_elem = -1;
    remaining = 0;
    for (int i = 1; i <= last; i++)
    {
        if (ans[i])
            continue;
        if (!remaining)
        {
            cur_elem++;
            if (cur_elem < serial.size() && serial[cur_elem] == 1)
                cur_elem++;
            if (cur_elem >= serial.size())
                continue;
            remaining = serial[cur_elem] - 1;
        }
        ans[i] = serial[cur_elem], remaining--;
    }
    reverse(serial.begin(), serial.end());
    cur_elem = -1;
    for (int i = last; i > 0; i--)
    {
        if (ans[i])
        {
            continue;
        }
        if (!remaining)
        {
            cur_elem++;
            if (cur_elem < serial.size() && serial[cur_elem] == n)
                cur_elem++;
            if (cur_elem >= serial.size())
                continue;
            remaining = n - serial[cur_elem];
        }
        ans[i] = serial[cur_elem], remaining--, low[serial[cur_elem]] = i;
    }
    for (auto [pos, val] : v)
    {
        if (pos > low[val])
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
    for (int i = 1; i <= last; i++)
        cout << ans[i] << " ";
    cout << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}