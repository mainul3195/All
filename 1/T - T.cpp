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
    int ans=0;
    for(int i=0, j=0; i<n && j<n;)
    {
        int dif=v[j]-v[i];
        if(dif==k)
        {
            ans++;
            i++;
        }
        else if(dif<k)
            j++;
        else
            i++;        
    }
    cout << ans << "\n";
    return 0;
}