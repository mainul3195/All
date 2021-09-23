#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
struct pr
{
    int x, y;
};
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    while(cin >> n and n)
    {
        vector<long long> num(n);
        for(int i=0; i<n; i++)
            cin >> num[i];
        sort(num.begin(), num.end());
        map<long long, pr> mp;
        for(int i=0; i<n-3; i++)
            for(int j=i+1; j<n-2; j++)
            {
                long long t=num[i]+num[j];
                mp[t]={i+1,j+1};
            }
        bool ok=1;
        for(int i=n-1; i>2; i--)
        {
            if(!ok)
                break;
            for(int j=i-1; j>1;  j--)
            {
                pr tm = mp[num[i]-num[j]];
                if(!tm.x or tm.x==j+1 or tm.y==j+1)
                    continue;
                ok=0;
                cout << num[i] << "\n";
                break;
            }
        }
        if(ok)
            cout << "no solution\n";
    }
    return 0;
}