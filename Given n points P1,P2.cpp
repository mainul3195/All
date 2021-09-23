#include<bits/stdc++.h>
#define infinity 1e+15
using namespace std;

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
};
double tangent(pt a)
{
    if(a.x==0)
        return infinity;
    double tan=(double)a.y/a.x;
    if(fabs(tan)<1e-12)
        tan=0;
    return tan;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q;
    cin >> n >> q;
    vector<pt> point(n);
    for(int i=0; i<n; i++)
        point[i].input();
    vector<vector<double>> t(n);
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            double tan = tangent(point[i] - point[j]);
            t[i].push_back(tan);
            t[j].push_back(tan);
        }
        sort(t[i].begin(), t[i].end());
    }
    while(q--)
    {
        pt a;
        a.input();
        long long ans1=0,ans2=0;
        vector<double> tan_of_a;

        //right angle is not at pont A
        for(int i=0; i<n ; i++)
        {
            pt p=point[i]-a, perpendicular_p={-p.y, p.x};
            double tan = tangent(perpendicular_p);
            tan_of_a.push_back(tangent(p));
            int count= upper_bound(t[i].begin(), t[i].end(), tan) - 
                       lower_bound(t[i].begin(), t[i].end(),tan);
            ans1 += count;
        }
        sort(tan_of_a.begin(), tan_of_a.end());
        


        //right angle is at pont A
        for(int i=0; i<n; i++)
        {
            pt p=point[i]-a, perpendicular_p={-p.y, p.x};
            double tan = tangent(perpendicular_p);
            int count= upper_bound(tan_of_a.begin(), tan_of_a.end(), tan) - 
                       lower_bound(tan_of_a.begin(), tan_of_a.end(),tan);
            ans2 += count;
        }
        cout << ans1+ans2/2 << "\n";
    }
    return 0;

}