#include<iostream>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    map<int, int> mp;
    set<int> st;
    for(int i=0; i<n; i++)
    {
        int j;
        cin >> j;
        mp[j]++;
        st.insert(j);
    }
    int mx=0;
    for(auto i:st)
        mx = max(mx, (mp[i]+mp[i-1]+mp[i+1]));
    cout << mx << "\n";
    return 0;
}