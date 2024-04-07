#include <bits/stdc++.h>
using namespace std;
struct bar
{
    long long h, s;
};
long long solve(vector<int> v)
{
    v.push_back(0);
    stack<bar> st;
    long long area = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (st.empty() || v[i] > st.top().h)
            st.push({v[i], i});
        else
        {
            int start;
            while (st.size() && st.top().h >= v[i])
            {
                area = max(area, (i - st.top().s) * st.top().h);
                start = st.top().s;
                st.pop();
            }
            st.push({v[i], start});
        }
    }
    return area;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int r, c;
    cin >> r >> c;
    vector<vector<int>> grid(r, vector<int>(c));
    for (auto &R : grid)
        for (auto &C : R)
            cin >> C;
    for (int i = 1; i < r; i++)
        for (int j = 0; j < c; j++)
            if (grid[i][j])
                grid[i][j] += grid[i - 1][j];
    long long ans = 0;
    for (int i = 0; i < r; i++)
        ans = max(ans, solve(grid[i]));
    cout << ans << "\n";
    return 0;
}