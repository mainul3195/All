#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<vector<int>>adj(n+1);
        vector<int>indegree(n+1, 0), d(n+1, 0);
        queue<int>q;
        for(int i=1; i<=n; i++)
        {
            cin >>  indegree[i];
            if(!indegree[i])
            {
                q.push(i);
                d[i] = 1;
            }
            for(int j=1; j<=indegree[i]; j++)
            {
                int k;
                cin >> k;
                adj[k].push_back(i);
            }
        }
        int i, mx;
        for(i=0,mx = 1; q.size(); q.pop(), i++)
        {
            int f = q.front();
            for(auto k: adj[f])
            {
                d[k] = max(d[k], d[f]+(f>k));
                mx = max(mx, d[k]);
                indegree[k]--;
                if(!indegree[k])
                    q.push(k);
            }
        }
        cout << (i==n?mx:-1) << "\n";
    }
    return 0;
}






// #include<bits/stdc++.h>
// using namespace std;
// int n;
// vector<vector<int>>v;
// int main()
// {
//     ios_base::sync_with_stdio(0); cin.tie(0);
//     int t;
//     cin >> t;
//     while(t--)
//     {
//         cin >> n;
//         v = vector<vector<int>>(n+1);
//         vector<int>ind(n+1, 0);
//         for(int i=1; i<=n; i++)
//         {
//             int k;
//             cin >> k;
//             while(k--)
//             {
//                 int vt;
//                 cin >> vt;
//                 ind[i] ++;
//                 v[vt].push_back(i);
//             }
//         }
//         priority_queue<int, vector<int>, greater<int>> q;
//         for(int i=1; i<=n; i++)
//             if(!ind[i])
//                 q.push(i);
//         vector<int>ans;
//         while(!q.empty())
//         {
//             int tp = q.top();
//             ans.push_back(tp);
//             q.pop();
//             for(auto i: v[tp])
//             {
//                 ind[i]--;
//                 if(!ind[i])
//                     q.push(i);
//             }
//         }
//         if(ans.size()!=n)
//             cout << "-1\n";
//         else
//         {
//             set<int>st;
//             for(auto i: ans)
//             {
//                 auto it = st.lower_bound(i);
//                 if(it == st.begin()) st.insert(i);
//                 else
//                 {
//                     it--;
//                     st.erase(it);
//                     st.insert(i);
//                 }
//             }
//             cout << st.size() << "\n";
//         }
        
//     }

//     return 0;
// }
