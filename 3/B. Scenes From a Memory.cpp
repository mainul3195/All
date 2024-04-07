#include<bits/stdc++.h>
#define pi (2*acos(0.0))
#define Swap(x,y) (x)^=(y)^=(x)^=(y)
#define all(x) x.begin(), x.end()
using namespace std;
#define lim 10000
/*
#define ckbit(x) (fLd[(x)/32] & (1<<(x)%32))
#define cngbit(x) (fLd[(x)/32] != (1<<(x)%32))
int fLd[lim/32+2];
*/
#define ckbit(x) (fLd[(x)/64] & (1<<((x)%64)/2))
#define cngbit(x) (fLd[(x)/64] |= (1<<((x)%64)/2))
int fLd[lim/64+2];
vector<int> primes;
void sieve()
{
    primes.push_back(2);
    for(int i=3; i*i<=lim; i+=2)
        if(!ckbit(i))
            for(int j = i*i; j<=lim; j+=2*i)
                cngbit(j);
    for(int i=3; i<=lim; i+=2)
        if(!ckbit(i))
            primes.push_back(i);
    return;
}
map<int, bool> mp;
char ck1(string &s)
{
    for(auto i: s)
        if(!mp[i-48])
            return i;
    return 0;
}
string ck2(string &s)
{
    string tmp;
    for(int i=0; i<s.size()-1; i++)
        for(int j=1; j<s.size(); j++)
            if(!mp[10*(s[i]-48) + s[j]-48])
            {
                tmp += s[i];
                tmp += s[j];
                return tmp;
            }
    return tmp;
}string ck3(string &s)
{
    string tmp;
    for(int i=0; i<s.size()-2; i++)
        for(int j=1; j<s.size()-1; j++)
            for(int k=2; k<s.size(); k++)
            if(!mp[100*(s[i]-48) + 10*(s[j]-48) + s[k]-48])
            {
                tmp += s[i];
                tmp += s[j];
                tmp += s[k];
                return tmp;
            }
    return tmp;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    sieve();
    for(auto i: primes)
        mp[i] = true;
    int t;
    cin >> t;
    while(t--)
    {
        int k;
        string s;
        cin >> k >> s;
        char c = ck1(s);
        if(c)
        {
            cout << 1 << "\n" << c << "\n";
            continue;
        }
        string tm = ck2(s);
        if(tm.size())
        {
            cout << 2 << "\n" << tm << "\n";
            continue;
        }
        tm = ck3(s);
        cout << 3 << "\n" << tm << "\n";

    }

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