#include <bits/stdc++.h>
using namespace std;
int n;
int lim;
string s;
long long ans;
string dfs(int p)
{
    if (p * 2 + 1 >= lim)
        return "" + s[p];
    string left_string = dfs(2 * p + 1);
    string right_string = dfs(2 * p + 2);
    if (left_string != right_string)
        ans <<= 1;
    if (left_string > right_string)
        swap(left_string, right_string);
    return "" + s[p] + left_string + right_string;
}
void solve()
{
    ans = 1;
    cin >> n >> s;
    lim = (1 << n) - 1;
    // cout << lim << "\n";
    dfs(0);
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}