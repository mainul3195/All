#include <bits/stdc++.h>
using namespace std;
vector<int> v(3001);
void solve()
{
    int n;
    cin >> n;
    cout << v[n] << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 2; i <= 3000; i++)
        if (!v[i])
            for (int j = i; j <= 3000; j += i)
                v[j]++;
    for (auto &i : v)
        i = i == 2;
    for (int i = 1; i <= 3000; i++)
        v[i] += v[i - 1];
    solve();
    return 0;
}