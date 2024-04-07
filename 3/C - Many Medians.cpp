#include<iostream>
#include<vector>
#include<algorithm>
#define all(x) x.begin(), x.end()
using namespace std;
struct dbl
{
    int val, pos;
    void inp()
    {
        cin >> val;
    }
    bool operator < (const dbl &a)
    {
        return val<a.val || (val==a.val && pos<a.pos);
    }
};
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<dbl> v(n);
    vector<int> po(n);
    for(int i=0; i<n; i++)
    {
        v[i].inp();
        v[i].pos = i;
    }
    sort(all(v));
    for(int i=0; i<n; i++)
        po[v[i].pos] = i;
    int mid = n/2; 
    // for(auto i: v)
    //     cout << i.pos << " ";
    // cout << "\n";
    // for(auto i: po)
    //     cout << i << " ";
    // cout << "\n";
    for(int i=0; i<n; i++)
    {
        if(po[i]<mid)
            cout << v[mid].val << "\n";
        else 
            cout << v[mid-1].val << "\n";
    }
    return 0;
}