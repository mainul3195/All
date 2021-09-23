#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int gcd(int a, int b)
{
    if(!b)
        return a;
    return gcd(b, a%b);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
    v.push_back(x);
    sort(v.begin(), v.end());
    vector<int> div;
    for(int i=1; i<=n; i++)
        div.push_back(v[i]-v[i-1]);
    int g=div[0];
    for(int i=1; i<div.size(); i++)
        g=gcd(g, div[i]);
    cout << g << "\n";
    return 0;
}