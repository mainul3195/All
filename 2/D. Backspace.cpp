#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        string a, b;
        cin >> a >> b;
        int i=a.size()-1, j = b.size()-1;
        for(; i>=0 && j>=0;)
        {
            if(a[i]==b[j])
            {
                j--, i--;
                continue;
            }
            else i-=2;
        }
        if(j==-1)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}