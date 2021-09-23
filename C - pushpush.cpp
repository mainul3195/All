#include<iostream>
#include<vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i: v)
        cin >> i;
    int count =0;
    for(int i=n-1; i>=0; i-=2, count ++)
        cout << v[i] << " \n"[count == n];
    for(int i= n%2?1:0; i<n; i+=2, count ++)
        cout << v[i] << " \n"[count == n];
    return 0;
}