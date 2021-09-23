#include<iostream>
#include<vector>
#include<cmath>
#include<utility>
using namespace std;
#define MN 1e-9
double dis(double a, double b)
{
    return sqrt(a*a + b*b);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    double x,y,r;
    while(cin >> x >> y >> r and r>-MN)
    {
        int n;
        cin >> n;
        vector<pair<double, double> > v;
        for(int i=0; i<n; i++)
        {
            double t1,t2;
            cin >> t1 >> t2;
            t1-=x;
            t2-=y;
            if(dis(t1,t2)-r<MN)
            {
                pair<double, double> p=make_pair(t1, t2);
                v.push_back(p);
            }
        }
        // for(int i=0; i<v.size(); i++)
        // {
        //     cout << v[i].first << " " << v[i].second << "\n";
        // }
        int mx=0;
        for(int i=0; i<v.size(); i++)
        {
            int pmx=0, nmx=0;
            for(int j=0; j<v.size(); j++)
            {
                double cross = v[i].first*v[j].second - v[i].second*v[j].first;
                if(fabs(cross)<MN)
                    pmx++,nmx++;
                else if(cross>MN)
                    pmx++;
                else 
                    nmx++;
            }
            mx=max(mx, max(pmx, nmx));
        }
        cout << mx << "\n";
    }
    return 0;
}