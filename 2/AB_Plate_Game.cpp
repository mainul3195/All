#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b, r;
    cin >> a >> b >> r;
    if (min(a, b) >= 2 * r)
        cout << "First\n";
    else
        cout << "Second\n";
    return 0;
}