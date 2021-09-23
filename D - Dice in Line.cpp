#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<double>v;
    for(int i=0; i<n; i++)
    {
        int j;
        cin >> j;
        v.push_back((j+1)/2.0);
    }
    double sum=0;
    for(int i=0; i<k; i++)
        sum+=v[i];
    double mx=sum;
    for(int i=k; i<n; i++)
    {
        sum += v[i] - v[i-k];
        mx = max(mx, sum);
    }
    cout <<fixed << setprecision(8) <<  mx << "\n";
    return 0;
}