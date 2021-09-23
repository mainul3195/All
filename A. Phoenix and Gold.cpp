#include<bits/stdc++.h>
using namespace std;
int n;
void randomize(vector<int>&v)
{
    for(int i=0; i<n; i++)
    {
        srand(time(0));
        int t = rand()%n;
        if(i!=t) v[i] ^= v[t] ^= v[i] ^= v[t];
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int x;
        cin >>  n >> x;
        vector<int>v(n);
        for(auto &i: v)
            cin >> i;
        int i;
        for(i=0; i<90; i++)
        {
            randomize(v);
            int sum =0;
            bool ok = 1;
            for(auto j: v)
            {
                sum += j;
                if(sum == x)
                {
                    ok = 0;
                    break;
                }
            }
            if(ok)
            {
                cout << "YES\n";
                for(auto j: v)
                    cout << j << " ";
                cout << "\n";
                break;
            }
        }
        if(i==90)
            cout << "NO\n";
    }
    return 0;
}