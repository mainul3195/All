#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    if (s.size() == 1)
    {
        cout << "0\n";
        return;
    }
    int num = 0;
    for (auto c : s)
        num += c - '0';
    int ans = 1;
    while (num / 10)
    {
        int tmp = 0;
        while (num)
        {
            tmp += num % 10;
            num /= 10;
        }
        num = tmp;
        ans++;
    }
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