#include<bits/stdc++.h>
#define pi (2*acos(0.0))
#define Swap(x,y) (x)^=(y)^=(x)^=(y)
#define all(x) x.begin(), x.end()
using namespace std;
struct pr
{
    int col,cnt;
    bool operator < (const pr &a)const{
        return cnt>a.cnt || (cnt == a.cnt && col<a.col);
    }
};
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n, l, j, r;
        cin >> n >> l >> r;
        map<int, int> leftColor, rightColor;
        for(int i = 0; i<l; i++)
        {
            cin >> j;
            leftColor[j]++;
        }
        for(int i=0; i<r; i++)
        {
            cin >> j;
            rightColor[j]++;
        }
        set<pr>leftSet, rightSet;
        int ans = 0;

        //partitioning
        if(l<r)
        {
            for(auto i: rightColor)
                rightSet.insert({i.first, i.second});
            int need = (r-l)/2;
            for(auto i: rightSet)
            {
                if(i.cnt>leftColor[i.col])
                {
                    int avail = (i.cnt-leftColor[i.col]+1)/2;
                    if(avail>=need)
                        avail = need;
                    need -= avail;
                    rightColor[i.col] -= avail;
                    leftColor[i.col] += avail;
                    ans += avail;
                }
                if(!need) break;
            }
            if(need)
            {
                for(auto i: rightColor)
                {
                    int avail = min(i.second, need);
                    need -= avail;
                    i.second -= avail;
                    leftColor[i.first] += avail;
                    ans += avail;
                    if(!need)break;
                }
            }
        }
        else if(l>r)
        {
            for(auto i: leftColor)
                leftSet.insert({i.first, i.second});
            int need = (l-r)/2;
            for(auto i: leftSet)
            {
                if(i.cnt>rightColor[i.col])
                {
                    int avail = (i.cnt-rightColor[i.col]+1)/2;
                    if(avail>=need)
                        avail = need;
                    need -= avail;
                    leftColor[i.col] -= avail;
                    rightColor[i.col] += avail;
                    ans += avail;
                }
                if(!need) break;
            }
            if(need)
            {
                for(auto i: leftColor)
                {
                    int avail = min(i.second, need);
                    need -= avail;
                    i.second -= avail;
                    rightColor[i.first] += avail;
                    ans += avail;
                    if(!need)break;
                }
            }
        }

        //equaling colors
        int ltr=0, rtl=0;
        for(auto i: leftColor)
            if(i.second)
                ltr += i.second-min(rightColor[i.first], i.second);
        for(auto i: rightColor)
            if(i.second)
                rtl += i.second-min(leftColor[i.first], i.second);
        cout << ans+min(rtl, ltr) << "\n";
    }

    return 0;
}
/*
gcd
leftColorm
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