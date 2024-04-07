#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while (cin >> n && n)
    {
        if (n & 1)
            cout << "ailyanlu\n";
        else
            cout << "8600\n";
    }
    return 0;
}