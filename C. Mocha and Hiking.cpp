#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie();
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int f=-1,j;
        for(int i=0; i<n; i++)
        {
            cin >> j;
            if(j && f==-1)
                f = i;
        }
        if( f != -1 )
        {
            for(int i=1; i<=f; i++)
                cout << i << " ";
            cout << n+1 << " ";
            for(int i=f+1; i<=n; i++)
                cout << i << " \n"[i==n];
        }
        else
            for(int i=1; i<=n+1; i++)
                cout << i << " \n"[i==n+1];
    }
    return 0;
}