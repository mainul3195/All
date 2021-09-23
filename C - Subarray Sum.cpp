#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k , s;
    cin >> n >> k >> s;
    for(int i=0; i<n; i++)
    {
        if(i<k)
            cout << s << " \n"[i==n-1];
        else 
            cout << (s==1000000000? 99999999: 1000000000) << " \n"[i==n-1];
    }
    return 0;
}