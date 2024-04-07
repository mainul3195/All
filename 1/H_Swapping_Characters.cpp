#include<bits/stdc++.h>
using namespace std;
vector<int>dif;
int n, k;
int mismatched(string &a, string &b, int store)
{
    vector<int>na(26, 0), nb(26, 0);
    set<char>st;
    for(auto i: a)
        st.insert(i);
    for(auto i: a)
        na[i-'a']++;
    for(auto i: b)
        nb[i-'a']++;
    if(na != nb)
        return 10;
    int count = 0;
    for(int i = 0; i<k; i++)
        if(a[i] != b[i])
        {
            if(store)
                dif.push_back(i);
            count ++;
        }
    if(!count && st.size()==k) return 10;
    return count;
}
void solve()
{
    cin >> n >> k;
    vector<string> v(n);
    for(auto &i: v)
        cin >> i;
    bool allsame = 1;
    for(int i = 1; i<n; i++)
        if(v[i]!=v[i-1])
        {
            allsame = 0;
            break;
        }
    if(allsame)
    {
        swap(v[0][0], v[0][1]);
        cout << v[0] << "\n";
        return;
    }
    bool possible = 1;
    for(int i = 0; possible && i<n; i++)
        for(int j = i+1; j<n; j++) 
            if(v[i]!=v[j])
            {
                dif.clear();
                int nod = mismatched(v[i], v[j], 1);
                if(nod>4)
                {
                    possible = 0;
                    break;
                }
                for(auto str: {i, j})
                    for(auto ind: dif)
                    {
                        for(int l = 0; l<k; l++)
                        {
                            string tmp = v[str];
                            swap(tmp[l], tmp[ind]);
                            bool ok = 1;
                            for(int m = 0; m<n; m++) if(m!=str)
                            {
                                int difcount = mismatched(tmp, v[m], 0);
                                // cout << difcount << "\n";
                                if(difcount != 0 && difcount!=2)
                                {
                                    ok = 0;
                                    break;
                                }
                            }
                            if(ok)
                            {
                                cout << tmp << "\n";
                                return;
                            }
                        }
                    }
            }
    cout << "-1\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve(); 
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
bit
sparseTable
vll
pi
ll
Pair
all
mll
mii
mis
msi
vvi
vi
pb
inf
linf
*/