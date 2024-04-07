#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve()
{
    vector<int> v;
    int n;
    cin >> n;
    int num[n];
    for (int i = 0; i < n; i++)
        cin >> num[i];
    sort(num, num + n);
    int prev = 0;
    for (int i = 0; i < n; i++)
    {
        v.push_back(num[i] - prev - 1);
        prev = num[i];
    }
    v.push_back(0);
    reverse(v.begin(), v.end());
    int x = 0;
    for (int i = 1; i < v.size(); i += 2)
        x ^= v[i];
    if (x)
        cout << "Georgia will win\n";
    else
        cout << "Bob will win\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}