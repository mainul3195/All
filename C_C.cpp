#include <bits/stdc++.h>
using namespace std;
#define inf 1000000000000000
void solve()
{
    long long l1, l2, l3, c1, c2, c3;
    cin >> l1 >> l2 >> l3 >> c1 >> c2 >> c3;
    int n;
    cin >> n;
    int s, e;
    cin >> s >> e;
    if (s > e)
        s ^= e ^= s ^= e;
    vector<long long> v(n + 1, 0);
    for (int i = 2; i <= n; i++)
        cin >> v[i];
    vector<long long> dis1(n + 2, inf), dis2(n + 2, inf), dis3(n + 3, inf);
    dis1[s] = dis2[s] = dis3[s] = 0;
    for (int i = s; i <= e; i++)
    {
        dis1[i] = dis2[i] = dis3[i] = min({dis1[i], dis2[i], dis3[i]});
        int j = i + 1;
        while (j <= e && v[j] - v[i] <= l1)
        {
            dis1[j] = min(dis1[j], dis1[i] + c1);
            j++;
        }
        j = i + 1;
        while (j <= e && v[j] - v[i] <= l2)
        {
            dis2[j] = min(dis2[j], dis2[i] + c2);
            j++;
        }
        j = i + 1;
        while (j <= e && v[j] - v[i] <= l3)
        {
            dis3[j] = min(dis3[j], dis3[i] + c3);
            j++;
        }
    }
    cout << dis1[e] << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}