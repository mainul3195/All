#include<bits/stdc++.h>
using namespace std; 
struct pt
{
    long long x,y;
    void input()
    {
        cin >> x >> y;
    }
    long long operator & (const pt &a)
    {
        return x*a.y-y*a.x;
    }
};
int main()
{
    int t;
    cin >> t;
    int tc=0;
    while(t--)
    {
        cout << "Case " << ++tc << ": ";
        int n;
        cin >> n;
        vector<pt> point(n+1);
        long long b=0;
        for(int i=0; i<n; i++)
        {
            point[i].input();
        }
        long long ans=0;
        point[n]=point[0];
        for(int i=0; i<n; i++)
        {
            b += __gcd(max(point[i].x, point[i+1].x)-min(point[i].x, point[i+1].x),
                       max(point[i].y, point[i+1].y)-min(point[i].y, point[i+1].y)) -1 ;
            ans += point[i] & point[i+1];
        }
        b+=n;
        if(ans<0)
            ans = -ans;
        
        cout <<  (ans - b +2)/2 << "\n";
    }
    return 0;
}