#include <bits/stdc++.h>
using namespace std;
#define int long long
struct nd
{
    long long x, y, l, r, dif;
};
vector<nd> v;
int n;
void solve()
{
    cin >> n;
    v = vector<nd>(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].x;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].y;
        v[i].y <<= 1;
        v[i].l = v[i].r = i;
        v[i].dif = v[i].y - v[i].x;
    }
    vector<nd> tmp;
    for (int i = 0; i < n; i++)
    {
        if (v[i].dif > 0)
        {
            tmp.push_back(v[i]);
            continue;
        }
        nd cur = v[i];
        long long sx = 0, sy = 0;
        while (i < n && v[i].dif <= 0)
        {
            sx += v[i].x;
            sy += v[i].y;
            i++;
        }
        i--;
        tmp.push_back({sx, sy, cur.l, v[i].r, sy - sx});
    }
    int one_count = 0, zero_count = 0;
    for (auto [x, y, l, r, d] : tmp)
        (d <= 0) ? zero_count++ : one_count++;
    if (one_count > zero_count)
    {
        vector<pair<int, int>> ranges;
        for (auto [x, y, l, r, d] : tmp)
            if (l != r)
                ranges.push_back({l, r});
        cout << "Yes\n";
        cout << ranges.size() << "\n";
        for (auto [a, b] : ranges)
            cout << a + 1 << " " << b + 1 << "\n";
        return;
    }
    if (one_count == zero_count)
    {
        int index = -1;
        for (int i = 0; i < tmp.size(); i++)
        {
            if (tmp[i].dif <= 0)
            {
                if (i)
                {
                    if (tmp[i - 1].x + tmp[i].x < tmp[i - 1].y + tmp[i].y)
                    {
                        index = i - 1;
                        break;
                    }
                }
                if (i < tmp.size() - 1)
                {
                    if (tmp[i].x + tmp[i + 1].x < tmp[i].y + tmp[i + 1].y)
                    {
                        index = i;
                        break;
                    }
                }
            }
        }
        if (index == -1)
        {
            cout << "No\n";
            return;
        }
        vector<pair<int, int>> ranges;
        for (int i = 0; i < tmp.size(); i++)
        {
            if (i == index)
            {
                ranges.push_back({tmp[i].l, tmp[i + 1].r});
                i++;
            }
            else
            {
                if (tmp[i].l != tmp[i].r)
                    ranges.push_back({tmp[i].l, tmp[i].r});
            }
        }
        cout << "Yes\n";
        cout << ranges.size() << "\n";
        for (auto [a, b] : ranges)
            cout << a + 1 << " " << b + 1 << "\n";
    }
    else
    {
        vector<int> index;
        int booked = -1;
        for (int i = 0; i < tmp.size(); i++)
        {
            if (tmp[i].dif <= 0)
            {
                if (i - 1 != booked)
                {
                    if (tmp[i - 1].x + tmp[i].x < tmp[i - 1].y + tmp[i].y)
                    {
                        index.push_back(i - 1);
                        booked = i;
                        continue;
                    }
                }
                if (i < tmp.size() - 1)
                {
                    if (tmp[i].x + tmp[i + 1].x < tmp[i].y + tmp[i + 1].y)
                    {
                        index.push_back(i);
                        booked = i + 1;
                        i += 1;
                    }
                }
            }
            if (index.size() == 2)
                break;
        }
        if (index.size() == 2)
        {
            vector<pair<int, int>> ranges;
            for (int i = 0; i < tmp.size(); i++)
            {
                if (i == index[1] || i == index[0])
                {
                    ranges.push_back({tmp[i].l, tmp[i + 1].r});
                    i++;
                }
                else
                {
                    if (tmp[i].l != tmp[i].r)
                        ranges.push_back({tmp[i].l, tmp[i].r});
                }
            }
            cout << "Yes\n";
            cout << ranges.size() << "\n";
            for (auto [a, b] : ranges)
                cout << a + 1 << " " << b + 1 << "\n";
            return;
        }
        long long cum_sum = 0, mn = 1000000000000000LL, ind = -1, nd = -1;
        for (int i = 0; i < tmp.size(); i++)
        {
            cum_sum += tmp[i].dif;
            if (i & 1)
            {
                if (cum_sum < mn)
                {
                    mn = cum_sum;
                    ind = i + 1;
                }
            }
            else
            {
                if (mn < cum_sum)
                {
                    nd = i;
                    break;
                }
            }
        }
        if (nd == -1)
        {
            cout << "No\n";
            return;
        }
        vector<pair<int, int>> ranges;
        for (int i = 0; i < tmp.size(); i++)
        {
            if (i == ind)
            {
                ranges.push_back({tmp[ind].l, tmp[nd].r});
                i = nd;
            }
            else
            {
                if (tmp[i].l != tmp[i].r)
                    ranges.push_back({tmp[i].l, tmp[i].r});
            }
        }
        cout << "Yes\n";
        cout << ranges.size() << "\n";
        for (auto [a, b] : ranges)
            cout << a + 1 << " " << b + 1 << "\n";
    }
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}