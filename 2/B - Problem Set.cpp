#include<iostream>
#include<map>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n;
    map<int, int> dif;
    for(int i=0; i<n; i++)
    {
        int j;
        cin >> j;
        dif[j]++;
    }
    map<int, int> req;
    cin >> m;
    for(int i=0; i<m; i++)
    {
        int j;
        cin >> j;
        req[j]++;
    }
    bool ok=1;
    for(auto i: req)
    {
        if(i.second > dif[i.first])
        {
            ok=0;
            break;
        }
    }
    if(ok)
        cout << "YES\n";
    else 
        cout << "NO\n";
    return 0;
}