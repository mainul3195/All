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
        long long ans = (1<<63)-1;
        for(int i=0; i<n; i++)
        {
            int j;
            cin >> j;
            ans &= j;
        }
        cout << ans << "\n";
    }
    return 0;
}