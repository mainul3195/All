#include<bits/stdc++.h>
using namespace std;
struct pr{
    int workerno, cando;
    bool operator<(const pr &a) const{
        return cando>a.cando || (cando == a.cando && workerno <a.workerno);
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    map<int ,vector<int>>mp;
    for(int i = 1; i<=m; i++){
        int w;
        cin >> w;
        mp[w].push_back(i);
    }
    set<pr> st;// cando,workers
    for(auto [i, j]: mp){
        st.insert({i, j});
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}

