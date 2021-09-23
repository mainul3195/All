#include<bits/stdc++.h>
#define ll long long
#define vci vector<int>
#define vcll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define mpii map<int, int>
#define mpll map<long long, long long>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int status= 1;
    vector<int> v(n);
    for(auto &i: v)
        cin >> i;
    if(n==1)
    {
        cout << "0\n";
        return;
    }
    int c=-1;
    bool ok=0;
    for(int i=0; i<n-1; i++)
        if(v[i]<v[i+1])
        {
            if(ok && c==v[i+1]-v[i])
                break;
            else if(ok && c!= v[i+1]-v[i])
            {
                c=-1;
                status = -1;
                break;
            }
            else if(!ok)
            {
                c=v[i+1]-v[i];
                ok=1;
            }
        }
    int tp_ind=-1;
    for(int i=0; i<n-1; i++)
        if(v[i]>v[i+1])
        {
            tp_ind = i;
            break;
        }
    if(tp_ind == -1 && status != -1)
    {
        int dif=v[1]-v[0];
        bool done = 0;
        for(int i=1; i<n-1; i++)
        {
            if(v[i+1]-v[i] != dif)
            {
                status = -1;
                done = 1;
                break;
            }
        }
        if(!done)
            status = 0;
    }
    if(status != 1)
    {
        cout << status << "\n";
        return;
    }
    long long mx=-1;
    for(int i=0; i<n; i++)
        if(v[i]>mx)
        {
            mx=v[i];
            tp_ind = i;
        }
    int m = v[tp_ind]+c - v[tp_ind+1];
    if(m<=mx)
    {
        cout << "-1\n";
        return;
    }
    for(int i=1; i<n; i++)
        if(v[i] != (v[i-1]+c)%m)
        {
            status = -1;
            break;
        }
    if(status == 1)
        cout << m << " " << c << "\n";
    else cout << "-1\n";
    return;

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}