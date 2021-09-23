#include<iostream>
#include<vector>
using namespace std;
struct point
{
    long long x, y;
    void inp()
    {
        cin >> x >> y;
    }
};
vector<point> polygon[102];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        for(int i=0; i<n+2; i++)
            polygon[i].clear();
        for(int i=0; i<n; i++)
        {
            int m;
            cin >> m;
            for(int j=0; j<m; j++)
            {
                point p ;
                
            }
        }
    }
}