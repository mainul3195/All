#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    vector<int> sm;
    int same;
    for(int i=1; i<n; i++)
    {
        same=1;
        while(i<n && v[i]==v[i-1])
        {
            same++;
            i++;
        }
        sm.push_back(same);
    }
    if(n>1 && v[v.size()-1]!= v[v.size()-2])
        sm.push_back(1);
    sort(sm.begin(), sm.end());
    long long ans=0;
    for(int i=0, lim=sm.size()-k; i<lim; i++)
        ans += sm[i];
    cout << ans << "\n";

    return 0;
}