#include<bits/stdc++.h>
using namespace std;

struct pt
{
    long long x,y;
    void inp()
    {
        cin >> x >> y;
    }
    bool operator < (const pt &a)
    {
        return y<a.y or (y==a.y and x<a.x);
    }
    pt operator + (const pt &a)
    {
        return {x+a.x, y+a.y};
    }
    pt operator - (const pt &a)
    {
        return {x-a.x, y-a.y};
    }
    long long operator ^ (const pt &a)
    {
        return x*a.y- y*a.x;
    }
};
int ori(pt a, pt b, pt c)
{
    pt ab = b-a;
    pt bc = c-b;
    long long sin_b=ab ^ bc;
    return sin_b>0? 1 : sin_b==0? 0: -1;
}
void convex_hull(vector<pt> &a)
{
    vector<pt> left, right;
    sort(a.begin(), a.end());
    left.push_back(a[0]);
    right.push_back(a[0]);
    for(int i=1; i<a.size(); i++)
    {
        if(ori(a[0], a[i], a.back())==1 or i+1==a.size())
        {
            while(right.size()>=2 && ori(right[right.size()-2], right.back(), a[i])!=1)
                right.pop_back();
            right.push_back(a[i]);
        }
        if(ori(a[0], a[i], a.back())==-1 or i+1==a.size())
        {
            while(left.size()>=2 && ori(left[left.size()-2], left.back(), a[i])!=-1)
                left.pop_back();
            left.push_back(a[i]);
        }
    }
    a=right;
    for(int i=left.size()-2; i; i--)
        a.push_back(left[i]);
}
long long triangle_area(pt a, pt b, pt c)
{
    return abs((b-a) ^ (c-a));
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<pt> a(n);
    for(int i=0; i<n; i++)
        a[i].inp();
    convex_hull(a);
    long long ans=0;
    n=a.size();
    for(int i=0; i+2 < n; i++)
    {
        int pos=i+2,tempos=pos;
        for(int j=i+1; j+1 < n ;j++)
        {
            long long height_size = 0;
            pos=tempos;
            for(int k=pos; k<n; k++)
            {
                long long ta = triangle_area(a[i], a[j], a[k]);
                if(ta>height_size)
                {
                    height_size = ta;
                    tempos = k;
                    ans=max(ans, height_size);
                }
                else
                    break;
            }
            for(int k=pos-1; k>j; k--)
            {
                long long ta = triangle_area(a[i], a[j], a[k]);
                if(ta>height_size)
                {
                    height_size = ta;
                    tempos = k;
                    ans=max(ans, height_size);
                }
                else 
                    break;
            }
        }
    }
    cout << fixed << setprecision (7) << ans/2.0 << "\n";
    return 0;
}