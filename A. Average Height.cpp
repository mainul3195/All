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
    vector<int> even, odd;
    for(int i=0; i<n; i++)
    {
        int j;
        cin >> j;
        if(j%2)
            odd.push_back(j);
        else 
            even.push_back(j);
    }
    int count = 0;
    for(int i=0; i<odd.size(); i++)
        cout << odd[i] << " \n"[++count == n];
    for(int i=0; i<even.size(); i++)
        cout << even[i] << " \n"[++count == n];
    return ;
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