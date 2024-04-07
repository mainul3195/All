#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> v(n);
    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    if (v[0] == v[1] && v[1] == v[2])
    {
        long long count = 0;
        int nm = v[0];
        for (auto i : v)
        {
            if (i != nm)
                break;
            count++;
        }
        cout << count * (count - 1) * (count - 2) / 6 << "\n";
    }
    else if (v[1] != v[2])
    {
        int count = 0;
        int nm = v[2];
        for (int i = 2; i < n; i++)
        {
            if (v[i] != nm)
                break;
            count++;
        }
        cout << count << "\n";
    }
    else
    {
        long long count = 0;
        int nm = v[1];
        for (int i = 1; i < n; i++)
        {
            if (v[i] != nm)
                break;
            count++;
        }
        cout << count * (count - 1) / 2 << "\n";
    }

    return 0;
}