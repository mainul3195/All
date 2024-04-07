#include <bits/stdc++.h>
using namespace std;
bool different(int n)
{
    set<int> s;
    while (n)
    {
        s.insert(n % 10);
        n /= 10;
    }
    return s.size() == 4;
}
void solve()
{
    int n;
    cin >> n;
    while (!different(++n))
        ;
    cout << n << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}