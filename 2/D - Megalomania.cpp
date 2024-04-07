#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
struct work{
    long long no, dl;
    void inp()
    {
        cin >> no >> dl;
    }
    bool operator < (const work &a)
    {
        return dl<a.dl ||( dl == a.dl && no<a.no);
    }
};
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<work> v(n);
    for(auto &i: v)
        i.inp();
    sort(all(v));
    long long cur = 0;
    bool ok = 1;
    for(int i=0; i<n; i++)
    {
        cur += v[i].no;
        if(cur>v[i].dl)
        {
            ok = 0;
            break;
        }
    }
    if(ok)
        cout << "Yes\n";
    else    
        cout << "No\n";
    return 0;
}