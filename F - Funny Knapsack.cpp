#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
long long w;
void permutation_sum(long long i, long long sum, vector<long long> &per, vector<long long> &v)
{
    if(i==v.size())
    {
        per.push_back(sum);
        return;
    }
    permutation_sum(i+1, sum, per, v);
    permutation_sum(i+1, (sum+v[i]), per , v);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    int tc=0;
    while(t--)
    {
        cout << "Case " << ++tc << ": ";
        int n;
        cin >> n;
        cin >> w;
        int n1=n/2;
        int n2=n-n1;
        vector<long long> v1(n1), v2(n2);
        for(int i=0; i<n1; i++)
            cin >> v1[i];
        for(int i=0; i<n2; i++)
            cin >> v2[i];
        vector<long long> p1, p2;
        permutation_sum(0, 0, p1, v1);
        permutation_sum(0, 0, p2, v2);
        sort(p1.begin(), p1.end());
        sort(p2.begin(), p2.end());
        long long ans=0;
        for(auto i: p1)
        {
            if(i<=w)
            {
                auto it= lower_bound(p2.begin(), p2.end(), w-i+1);
                ans+=it-p2.begin();
            }
        }
        cout << ans << "\n";
    }
    return 0;
}