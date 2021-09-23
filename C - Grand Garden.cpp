#include<iostream>
#include<vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int>v(n+1, 0);
    for(int i=0; i<n; i++)
        cin >> v[i];
    int ans=0;
    for(int i=0; i<n; i++)
        if(v[i]-v[i+1]>0)
            ans += v[i]-v[i+1];
    cout << ans << "\n";
    return 0;
}