#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> v(n), left(n, 10000000), right(n, 10000000);
    for (auto &i : v)
        cin >> i;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
            left[i] = 0;
        else if (i)
            left[i] = left[i - 1] + 1;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (v[i] == 0)
            right[i] = 0;
        else if (i < n - 1)
            right[i] = right[i + 1] + 1;
    }
    for (int i = 0; i < n; i++)
        cout << min(left[i], right[i]) << " ";
    cout << "\n";
    return 0;
}