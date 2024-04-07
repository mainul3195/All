#include<bits/stdc++.h>
#define ll long long
#define vci vector<int>
#define vcll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define mpii map<int, int>
#define mpll map<long long, long long>
using namespace std;
struct deck{
    int val, pos;
    bool operator < (const deck &a);
};
bool deck :: operator < (const deck &a)
{
    return val>a.val;
}
void solve()
{
    int n;
    cin >> n;
    vector<deck> v(n);
    for(int i=0; i<n; i++)
    {
        cin >> v[i].val;
        v[i].pos=i;
    }
    vector<deck> v1=v;
    sort(v1.begin(), v1.end());
    int last = n-1;
    int c=0;
    for(int i=0; i<n; i++)
    {
        if(v1[i].pos>last)
            continue;
        for(int j=v1[i].pos; j<=last; j++)
            cout << v[j].val << " \n"[++c==n];
        last = v1[i].pos - 1;
    }
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