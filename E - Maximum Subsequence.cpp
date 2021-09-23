#include<iostream>
#include<vector>
#include<set>
using namespace std;
int m;
void rec(long long i, long long sum, set<long long> &per, vector<long long> &v)
{
    per.insert(sum);
    if(i==v.size())
        return;
    rec(i+1, sum%m, per, v);
    rec(i+1, (sum+v[i])%m,per, v);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n >>m;
    int n1=n/2;
    int n2=n-n1;
    vector<long long> v1(n1), v2(n2);
    for(int i=0; i<n1; i++)
    {
        cin >> v1[i];
        v1[i] %= m;
    }
    for(int i=0; i<n2; i++)
    {
        cin >> v2[i];
        v2[i] %= m;
    }
    set<long long> p1, p2;
    rec(0,0,p1,v1);
    rec(0,0,p2,v2);
    vector<long long> target;
    for(auto i: p2)
        target.push_back(i);
    long long ans=0;
    for(auto i: p1)
    {
        long long need = m-i-1;
        auto it=lower_bound(target.begin(),target.end(),need);
        if(*it != need)
            it--;
        ans = max(ans, (i+*it)%m);
    }
    cout << ans << "\n";
    return 0;
}