#include <bits/stdc++.h>
using namespace std;
#define lim 16777216
int together[lim], ans[lim];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        set<char> st(s.begin(), s.end());
        vector<char> v(st.begin(), st.end());
        for (auto c : v)
            together[1 << (c - 'a')]++;
        for (int i = 0; i < v.size(); i++)
            for (int j = i + 1; j < v.size(); j++)
                together[(1 << (v[i] - 'a')) | (1 << (v[j] - 'a'))]++;
        if (v.size() == 3)
            together[(1 << (v[0] - 'a')) | (1 << (v[1] - 'a')) | (1 << (v[2] - 'a'))]++;
    }
    for (int i = 0; i < 24; i++)
        ans[1 << i] = together[1 << i];
    for (int i = 0; i < 24; i++)
        for (int mask = 0; mask < lim; mask++)
        {
            if (mask & (1 << i))
                ans[mask] += ans[mask ^ (1 << i)] - (mask^(1<<i)? together[mask]:0);
        }
    for (int i = 0; i < 40; i++)
        cout << i << " -> " << together[i] << " " << ans[i] << "\n";
    long long a = 0;
    for (int i = 0; i < lim; i++)
        a ^= (long long)ans[i] * ans[i];
    cout << a << "\n";
    return 0;
}