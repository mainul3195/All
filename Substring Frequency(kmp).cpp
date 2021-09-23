#include<bits/stdc++.h>
using namespace std;
int matchString(string test, string pattern)
{
    vector<int>lsp(pattern.size(), -1);
    int l=-1, r=1;
    while(r<pattern.size())
    {
        if(pattern[l+1]==pattern[r])
            lsp[r++]=l++ + 1;
        else
        {
            if(l==-1) r++;
            else l = -1;
        }
    }
    l = -1, r = 0;
    int ans = 0;
    while(r<test.size())
    {
        if(pattern[l+1]==test[r]) l++, r++;
        else
        {
            if(l==-1) r++;
            else l = lsp[l];            
        }
        if(l+1 == pattern.size())
            ans++, l=lsp[l];
    }
    return ans;
}
int main()
{
    int t, tc=0;
    cin >> t;
    while(t--)
    {
        string a, b;
        cin >> a >> b;
        cout << "Case " << ++tc << ": " << matchString(a, b) << "\n";
    }
    return 0;
}
