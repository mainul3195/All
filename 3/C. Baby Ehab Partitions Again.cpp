#include<bits/stdc++.h>
#define pi (2*acos(0.0))
#define Swap(x,y) (x)^=(y)^=(x)^=(y)
#define all(x) x.begin(), x.end()
using namespace std;
int n;
vector<int>v, ase, nai;
bool possible()
{
    int sum = 0;
    vector<int> tmp = v;
    for(auto i: tmp)
        sum += i;
    if(sum&1) return 0;
    sum/=2;
    sort(all(tmp));
    reverse(all(tmp));
    bool hobe = 0;
    for(auto i: tmp)
    {
        if(!hobe && i<=sum)
            sum-=i, ase.push_back(i);
        else nai.push_back(i);
        if(!sum) hobe = 1;
    }
    cout << sum << "\n";
    return hobe;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    v = vector<int>(n);
    for(auto &i: v)
        cin >> i;
    if(!possible())
    {
        cout << 0;
        return 0;
    }
    int lp = 100000000;
    int tmp;
    for(int i=0; i<n; i++)
    {
        if((v[i]&(-v[i]))<lp)
        {
            lp = (v[i]&(-v[i]));
            tmp = i+1;
        }
    }
    cout << 1 << "\n" << tmp << "\n";
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