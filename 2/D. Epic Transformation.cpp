#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        map<int, int> mp;
        cin >>  n;
        int mx = -1;
        int mxcount = 0;
        for(int i=0; i<n; i++)
        {
            int j;
            cin >> j;
            mp[j]++;
        }
        for(auto i: mp)
            if(i.second > mx)
                mx = i.second;
        int sum = 0;
        bool done = 0;
        for(auto i: mp)
        {
            if(!done && i.second == mx)
            {
                done = 1;
                continue;
            }
            sum += i.second;
        }
        if(n%2)
            cout << max(1, mx - sum) << "\n";
        else 
            cout << max(0, mx - sum) << "\n";

    }
    return 0;
}