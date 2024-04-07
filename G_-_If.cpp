#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> pf(10004);
int start, target;
vector<int> done;
bool found;
void prime_f()
{
    for (int i = 2; i <= 1000; i++)
        if (pf[i].size() == 0)
            for (int j = i + i; j <= 1000; j += i)
                pf[j].push_back(i);
    for (auto &v : pf)
        reverse(v.begin(), v.end());
    return;
}

int okdone(int s)
{
    // cout << s << endl;
    if (~done[s])
        return done[s];
    if (s > target)
        return 2000000000;
    if (s == target)
        return 0;
    int ans = 2000000000;
    for (auto f : pf[s])
        ans = min(ans, 1 + okdone(s + f));
    // if (ans == 2000000000)
    //     return ans;
    return done[s] = ans;
}
void solve()
{
    done = vector<int>(2004, -1);
    cin >> start >> target;
    int tmp = okdone(start);
    if (tmp == 2000000000)
        cout << "-1\n";
    else
        cout << tmp << "\n";
    // queue<pair<int, int>> q;
    // q.push({0, start});
    // while (q.size())
    // {
    //     auto [l, s] = q.front();
    //     if (s == target)
    //     {
    //         cout << l << "\n";
    //         return;
    //     }
    //     q.pop();
    //     if (!done[s])
    //         for (auto d : pf[s])
    //             if (s + d <= target)
    //                 q.push({l + 1, s + d});
    //     done[s] = 1;
    // }
    // cout << "-1\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    prime_f();
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}