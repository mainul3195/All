#include<bits/stdc++.h>
using namespace std;
#define infinity 1e15
struct pt
{
    long long x,y;
    void input()
    {
        cin >> x >> y;
    }
    pt operator - (const pt &a)
    {
        return {x-a.x, y-a.y};
    }
    long long operator * (const pt &a)//find distance
    {
        return ((x-a.x)*(x-a.x)+ (y-a.y)*(y-a.y));
    }
};
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("points.in", "r", stdin);
    int t;
    cin >> t;
    long long n;
    long double l, r;
    while(t--)
    {

        cin >> n >> l >> r;
        l*=l;
        r*=r;

        vector<pt> point(n);
        for(int i=0; i<n ;i++)
            point[i].input();
        int count=0;

        for(int i=0; i+2<n; i++)
            for(int j=i+1; j+1<n; j++)
                for(int k=j+1; k<n; k++)
                {
                    long long a= point[i]*point[j];//finding distance
                    long long b= point[j]*point[k];
                    long long c= point[k]*point[i];
                    if(a<b)
                        swap(a, b);
                    if(a<c)
                        swap(a, c);
                    if(b+c == a)
                    {
                        long double area=.25*b*c;
                        if(area >=l and area <=r)
                            count++;
                    }
                }
        cout << count  << '\n';
    }
    return 0;
}