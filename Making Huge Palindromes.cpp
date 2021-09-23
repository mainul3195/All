#include<bits/stdc++.h>
using namespace std;

int solve(string &a)
{
    string b = a;
    reverse(b.begin(), b.end());
    vector<int> lsp(b.size(), -1);
    int l=-1, r=1;
    while(r<b.size())
    {
        if(b[l+1]==b[r]) lsp[r++] = l++ + 1;
        else l==-1? r++: l = -1;
    }
    l = -1, r = 0;
    while(r<a.size())
    {
        if(a[r] == b[l+1]) l++, r++;
        else l==-1? r++: l = lsp[l];
    }
    return 2*a.size()-l-1;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, tc=0;
    cin >> t;
    while(t--)
    {
        string a;
        cin >> a;
        cout << "Case " << ++tc << ": " << solve(a) << "\n";
    }
    return 0;
}