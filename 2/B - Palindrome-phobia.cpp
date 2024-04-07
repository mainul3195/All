#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define all(x) x.begin(), x.end()
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    vector<int> v(3, 0);
    for(auto i: s)
        v[i-'a']++;
    sort(all(v));
    if(v[2]-v[0]>=2)
        cout << "NO\n";
    else 
        cout << "YES\n";
    return 0;
}