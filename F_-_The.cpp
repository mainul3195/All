#include <bits/stdc++.h>
using namespace std;
#define inf 100000000000000000
long long kadane(vector<long long> v)
{
    long long ans = 0;
    long long cur_sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        cur_sum = max(0LL, cur_sum + v[i]);
        ans = max(cur_sum, ans);
    }
    if (ans == 0)
    {
        ans = -inf;
        for (auto i : v)
            ans = max(ans, i);
    }
    return ans;
}
long long max_sum_ractangle(vector<vector<long long>> v)
{
    int r = v.size();
    int c = v[0].size();
    vector<long long> tmp;
    long long ans = -inf;
    for (int i = 0; i < r; i++)
    {
        tmp = vector<long long>(c, 0);
        for (int j = i; j < r; j++)
        {
            for (int k = 0; k < c; k++)
                tmp[k] += v[j][k];
            ans = max(ans, kadane(tmp));
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int r, c, h;
        cin >> r >> c >> h;
        vector<vector<vector<long long>>> heap(r, vector<vector<long long>>(c, vector<long long>(h)));
        vector<vector<vector<vector<long long>>>> nam_khuje_painai(r, vector<vector<vector<long long>>>(r, vector<vector<long long>>(c, vector<long long>(h, 0))));
        for (auto &i : heap)
            for (auto &j : i)
                for (auto &k : j)
                    cin >> k;
        for (int i = 0; i < r; i++)
            for (int l = 0; l <= i; l++)
                for (int j = 0; j < c; j++)
                    for (int k = 0; k < h; k++)
                    {
                        if (l == 0)
                            nam_khuje_painai[i][l][j][k] = heap[i][j][k];
                        else
                            nam_khuje_painai[i][l][j][k] = nam_khuje_painai[i][l - 1][j][k] + heap[i - l][j][k];
                    }
        long long ans = -inf;
        for (int i = 0; i < r; i++)
            for (int l = 0; l <= i; l++)
                ans = max(ans, max_sum_ractangle(nam_khuje_painai[i][l]));
        cout << ans << "\n";
        if (t)
            cout << "\n";
    }
    return 0;
}
