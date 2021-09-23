#include<bits/stdc++.h>
using namespace std;
map<string, int>mp;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int n1=0,n2=0;
        for(int i=0; i<s.size(); i+=2)
            n1 = n1*10 + s[i]-48;
        for(int i=1; i<s.size(); i+=2)
            n2 = n2*10 + s[i]-48;
        cout << (n1+1)*(n2+1)-2 << "\n";
    }
    return 0;
}