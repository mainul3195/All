#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int h, x, y, c;
        cin >> h >>  x >> y >> c;
        if((x+y/2)*h<=c)
            cout << "YES\n";
        else
            cout << "NO\n";        
    }
    return 0;
}