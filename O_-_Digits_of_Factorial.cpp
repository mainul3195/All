#include <bits/stdc++.h>
using namespace std;
vector<double> base10(1000006);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 1; i < 1000006; i++)
        base10[i] = log10(i);
    for (int i = 1; i < 1000006; i++)
        base10[i] += base10[i - 1];
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        cout << "Case " << tc << ": ";
        int n, b;
        cin >> n >> b;
        cout << (int)(base10[n] / log10(b)) + 1 << "\n";
    }
    return 0;
}