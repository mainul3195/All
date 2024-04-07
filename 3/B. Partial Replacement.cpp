#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int ans = 0;
        int fpos = -1;
        bool found = 0;
        vector<int> v(n+55, 0);
        for(int i=0; i<n; i++)
        {
            if(s[i]=='*')
            {
                if(!found)
                {
                    found = 1;
                    fpos = i;
                    ans = 1;
                }
                v[i] = 1;
            }
        }
        if(fpos == -1)
        {
            cout << "0\n";
            continue;
        }
        int lpos = fpos;
        for(int i=fpos; i<=n+k; i++)
        {
            if(v[i])
                lpos = i;
            v[i]= lpos;
        }
        for(int i=fpos; i< n;)
        {
            if(v[i]!=v[i+k])
            {
                ans ++;
                i=v[i+k];
            }
            else 
                i=i+k;
        }
        cout << ans << "\n";
    }
    return 0;
}