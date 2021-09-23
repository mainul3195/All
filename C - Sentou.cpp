#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long n,t,ans=0,last=0;
    cin >> n >> t;
    for(int i=0; i<n; i++)
    {   
        int j;
        cin >> j;
        if(j<last)
            ans+=(j+t-last);
        else
            ans+=t;
        last=j+t;
    }
    cout << ans << "\n";
    return 0;
}