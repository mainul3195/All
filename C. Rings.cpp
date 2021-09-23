#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        string s;
        cin >> n >> s;
        int fz = -1;
        for(int i=0; i<n; i++)
            if(s[i]=='0')
            {
                fz = i+1;
                break;
            }
        if(fz==-1)
        {
            cout << "1 " << n-1 << " 2 " << n << "\n";
            continue;
        }
        else if(fz<=n/2) cout << fz << " " << n << " " << fz+1 << " " << n << "\n";
        else cout << "1 " << fz << " 1 " << fz-1 << "\n";
    }
    return 0;
}