#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int orientation(int a1, int b1, int a2, int b2, int a3, int b3)
{
    return (a2-a1)*(b3-b1)-(b2-b1)*(a3-a1);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, x1, y1, x2, y2;
    while(cin >> n && n)
    {
        cin >> m >> x1 >> y1 >> x2 >> y2;
        vector<pair<int, int>>board(n);
        for(auto &i: board)
            cin >> i.first >> i.second;
        sort(board.begin(), board.end());
        vector<int>no_of_toys(n+1, 0);
        for(int i = 0; i<m; i++)
        {
            int x, y;
            cin >> x >> y;
            int s = 0, e = n-1, mid, ans;
            while(s<=e)
            {
                mid = (s+e)>>1;
                if(orientation(board[mid].second, y2, board[mid].first, y1, x, y)>0)
                {
                    ans = mid;
                    e = mid - 1;
                }
                else
                {
                    ans = mid+1;
                    s = mid + 1;
                }
            }
            no_of_toys[ans]++;
        }
        vector<int>count(m+1, 0);
        for(auto i: no_of_toys)
            if(i)
                count[i]++;
        cout << "Box\n";        
        for(int i = 0; i<=m; i++)
            if(count[i])
                cout << i << ": " << count[i] << "\n";
    }
    return 0;
}