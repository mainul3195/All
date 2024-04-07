#include <bits/stdc++.h>
using namespace std;
int solve(vector<long long> v)
{
    int n = v.size();
    if (n == 1)
        return 0;
    int zero_count = 0;
    for (auto i : v)
        if (!i)
            zero_count++;
    if (zero_count)
    {
        if (zero_count == n)
            return 0;
        else if (zero_count == n - 1)
        {
            if (v[0])
                return 0;
            else
                return 1;
        }
        else if (zero_count == 1)
        {
            vector<long long> nw;
            for (auto i : v)
                if (i)
                    nw.push_back(i);
            int tmp_ans = solve(nw);
            if (tmp_ans == 0)
                return 1;
            else
                return 2;
        }
        else if (zero_count == n - 2 && v[0])
            return 1;
        else
            return 2;
    }
    map<pair<long long, long long>, int> r;
    for (int i = 1; i < n; i++)
    {
        long long a = abs(v[i - 1]);
        long long b = abs(v[i]);
        long long g = __gcd(a, b);
        long long hor = a / g;
        long long lob = b / g;
        if (v[i - 1] * v[i] < 0)
            lob *= -1;
        r[{lob, hor}]++;
    }
    // for (auto [a, b] : r)
    //     cout << a.first << "/" << a.second << " -> " << b << "\n";
    if (r.size() == 1)
        return 0;
    if (r.size() > 3)
        return 2;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            long long a = abs(v[i]);
            long long b = abs(v[i + 1]);
            long long g = __gcd(a, b);
            long long hor = a / g;
            long long lob = b / g;
            if (v[i] * v[i + 1] < 0)
                lob *= -1;
            if (r[{lob, hor}] == 1 && r.size() == 2)
                return 1;
        }
        else if (i == n - 1)
        {
            long long a = abs(v[n - 2]);
            long long b = abs(v[n - 1]);
            long long g = __gcd(a, b);
            long long hor = a / g;
            long long lob = b / g;
            if (v[n - 2] * v[n - 1] < 0)
                lob *= -1;
            if (r[{lob, hor}] == 1 && r.size() == 2)
                return 1;
        }
        else
        {
            long long a = abs(v[i - 1]);
            long long b = abs(v[i]);
            long long c = abs(v[i + 1]);

            long long g1 = __gcd(a, b);
            long long g2 = __gcd(b, c);
            long long g3 = __gcd(a, c);

            long long hor1 = a / g1;
            long long lob1 = b / g1;
            if (v[i - 1] * v[i] < 0)
                lob1 *= -1;
            pair<long long, long long> r1 = {lob1, hor1};

            long long hor2 = b / g2;
            long long lob2 = c / g2;
            if (v[i] * v[i + 1] < 0)
                lob2 *= -1;
            pair<long long, long long> r2 = {lob2, hor2};

            long long hor3 = a / g3;
            long long lob3 = c / g3;
            if (v[i - 1] * v[i + 1] < 0)
                lob3 *= -1;
            pair<long long, long long> r3 = {lob3, hor3};

            // if (i == 2)
            // {
            //     cout << r1.first << " " << r1.second << "\n";
            //     cout << r2.first << " " << r2.second << "\n";
            //     cout << r3.first << " " << r3.second << "\n";
            // }

            r[r1]--;
            if (r[r1] == 0)
                r.erase(r.find(r1));
            r[r2]--;
            if (r[r2] == 0)
                r.erase(r.find(r2));
            r[r3]++;
            if (r.size() == 1)
                return 1;
            r[r1]++;
            r[r2]++;
            r[r3]--;
            if (r[r3] == 0)
                r.erase(r.find(r3));
        }
    }
    return 2;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> v(n);
    for (auto &i : v)
        cin >> i;
    cout << solve(v) << "\n";
    return 0;
}