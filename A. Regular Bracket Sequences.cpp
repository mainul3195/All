#include<bits/stdc++.h>
#define pi (2*acos(0.0))
#define Swap(x,y) (x)^=(y)^=(x)^=(y)
#define all(x) x.begin(), x.end()
using namespace std;
char getchar(char c)
{
    if(c=='(') return ')';
    return '(';
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s = "";
        for(int i=0; i<=n+1; i++)
            s += '(';
        for(int i=n; i>0; i--)
        {
            s[i]=')';
            s[i+1] = '(';
            for(int j=0; j<n; j++)
                cout << s[j];
            for(int j=n-1; j>=0; j--)
                cout << getchar(s[j]);
            cout << "\n";
        }
    }
    return 0;
    

    return 0;
}
/*
gcd
lcm
modfact
fact
pfsingle
pfmultiple
ncrsingle
ncrmod
bgmod
mdinverse
sieve
SegmentTree
kmp
*/