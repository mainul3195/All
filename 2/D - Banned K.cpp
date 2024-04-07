#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<long long> num(n);
    map<long long , long long> mp;
    for(int i=0; i<n; i++)
    {
        cin >> num[i];
        mp[num[i]]++;
    }
    long long tot=0;
    for(auto i:mp)
            tot += (i.second * (i.second-1)/2);
    for(int i=0; i<n; i++)
    {
        long long t=mp[num[i]];
        if(t>1)
            cout << tot - t*(t-1)/2 + (t-1)*(t-2)/2 << "\n";
        else
        {
            cout << tot << "\n";
        }
    }
    return 0;
}