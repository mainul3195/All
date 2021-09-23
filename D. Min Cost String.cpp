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
    long long n, k;
    cin >> n >> k;
    string s;
    for(int i=0; i<k-1; i++)
    {
        for(int j=i+1; j<k; j++)
        {
            s+=(char)(97+i);
            s+=(char)(97+j);
        }
    }
    if(k==1)
        s="a";
    string t = s;
    reverse(t.begin(), t.end());
    long long sz=s.size();
    long long lim = n/sz;
    for(int i=1; i<=lim; i++)
    {
        if(i%2)
            cout << s;
        else 
            cout << t;
    }
    long long last = n%sz;
    if(lim%2)
    {
        for(int i=0; i<last; i++)
            cout << t[i];
    }
    else
    {
        for(int i=0; i<last; i++)
            cout << s[i];
    }
    cout << "\n";

    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}