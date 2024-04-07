#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string a, b;
vector<vector<long long> > dp;
long long solve(int i = 0, int j = 0)
{
    if (i == a.size() || j == b.size())
        return 0;
    if (~dp[i][j])
        return dp[i][j];
    if (a[i] == b[j])
        return dp[i][j] = 1 + solve(i + 1, j + 1);
    return dp[i][j] = max(solve(i, j + 1), max(solve(i + 1, j), solve(i + 1, j + 1)));
}
int main()
{
    while (cin >> a >> b)
    {
        dp = vector<vector<long long> >(a.size() + 1, vector<long long>(b.size() + 1, -1));
        cout << solve() << "\n";
    }
    return 0;
}