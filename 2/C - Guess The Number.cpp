#include<iostream>
#include<vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> v(n, -1);
    bool ok=1;
    for(int i=0; i<m; i++)
    {
        int s, j;
        cin >> s >> j;
        if(v[s-1]!=-1 && v[s-1]!=j)
        {
            ok=0;
            break;
        }
        v[s-1]=j;
    }
    if(n>1 && v[0]==-1)
        v[0]=1;
    for(int i=0; i<n; i++)
        if(v[i]==-1)
            v[i]=0;
    if(v[0]==0 && n>1)
        ok=0;
    if(ok)
        for(int i=0; i<n; i++)
            cout << v[i];
    else 
        cout << "-1";
    cout << "\n";
    return 0;
}