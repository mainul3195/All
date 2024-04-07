#include<iostream>
#include<set>
#include<map>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    set<long long> st, mx;
    int n;
    map<int, int> mp;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        long long j;
        cin >> j;
        mp[j]++;
        if(st.find(j)!=st.end())
            mx.insert(j);
        else 
            st.insert(j);
    }
    auto it = mx.end();
    if(mx.size()>=1 && mp[*--it]>=4)
        cout << (*it)*(*it) << "\n";
    else if(mx.size()>=2)
        cout << (*it)*(*--it) << "\n";
    else 
        cout << "0\n";
    return 0;
}