#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long a, y, x;
        cin >> a >> y >> x;
        long long lit = (a*x+1)-(x*max(0ll, a-y));
        if(y<=a)
            lit --;
        cout << lit << "\n";
    }
    return 0;
}