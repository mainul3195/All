#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct quad{
    long long a, b, c, d;
    void inp()
    {
        cin >> a >> b >> c >> d;
    }
};
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<quad> v(n);
    for(int i=0; i<n; i++)
        v[i].inp();
    vector<long long> first, second;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            first.push_back(v[i].a+v[j].b);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            second.push_back(v[i].c+v[j].d);
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());
    int ans=0;
    for(auto i:first)
        ans += upper_bound(second.begin(), second.end(), -i)-lower_bound(second.begin(), second.end(), -i);
    cout << ans << "\n";
    return 0;
}