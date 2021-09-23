#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int mn = 2000;
        int c=0;
        for(int i=0; i<n; i++)
        {
            int j;
            cin >> j;
            if(j<mn)
            {
                mn=j;
                c=1;
            }
            else if(j==mn)
                c++;
        }
        cout << n-c << "\n";
    }
    return 0;
}