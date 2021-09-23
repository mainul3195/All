#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
void per_sum(int i, long long sum, set<long long> &per, vector<long long> &source)
{
    if(i==source.size())
    {
        per.insert(sum);
        return;
    }
    per_sum(i+1, sum, per, source);
    per_sum(i+1, sum+source[i], per, source);
    per_sum(i+1, sum+2*source[i], per, source);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    int tc=0;
    while(t--)
    {
        cout << "Case " << ++tc <<": ";
        int n, k;
        cin >> n >> k;
        int n1=n/2;
        int n2=n-n1;
        vector<long long>  v1(n1), v2(n2);
        for(int i=0; i<n1; i++)
            cin >> v1[i];
        for(int i=0; i<n2; i++)
            cin >> v2[i];
        set<long long> p1, p2;
        per_sum(0, 0, p1, v1);
        per_sum(0, 0, p2, v2);
        bool ok=0;
        for(auto i:p1)
        {
            if(i<=k && p2.find(k-i)!=p2.end())
            {
                ok=1;
                break;
            }
        }
        if(ok)
            cout << "Yes\n";
        else 
            cout << "No\n";
    }
    return 0;
}