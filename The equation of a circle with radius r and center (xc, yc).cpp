#include<bits/stdc++.h>
using namespace std;
#define MN 1e-9
pair<double, double> rotate(double x, double y, double ang)
{
    return {x*cos(ang) - y*sin(ang), y*cos(ang) + x*sin(ang)};
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    double x1,x2,y1,y2,r1,r2;
    while(cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2)
    {
        double dis=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        if(fabs(dis)<MN && fabs(r1-r2)<MN)
        {
            if(r1<MN)
            {
                if(fabs(x1<.0004))
                    x1=MN;
                if(fabs(x2<.0004))
                    x2=MN;
                cout <<fixed << setprecision(3) << "(" <<  x1 << "," << y1 << ")" << "\n";
                continue;
            }
            cout << "THE CIRCLES ARE THE SAME\n";
            continue;
        }
        if(r1+r2-dis<MN or max(r1,r2)-min(r1,r2)-dis>MN)
        {
            cout << "NO INTERSECTION\n";
            continue;
        }
        if(fabs(r1+r2-dis)<MN)
        {
            double t1=(r1*x2+r2*x1)/(r1+r2);
            double t2=(r1*y2+r2*y1)/(r1+r2);
            if(fabs(t1<.0004))
                t1=MN;
            if(fabs(x2<.0004))
                t2=MN;
            cout << fixed << setprecision(3) << "(" <<  t1 << "," << t2 << ")" << "\n";
        }
        else if(fabs(fabs(r1-r2)-dis)<MN)
        {
            double t1=(r1*x2-r2*x1)/(r1-r2);
            double t2=(r1*y2-r2*y1)/(r1-r2);
            if(fabs(t1<.0004))
                t1=MN;
            if(fabs(x2<.0004))
                t2=MN;
            cout << fixed << setprecision(3) << "(" <<  t1 << "," << t2 << ")" << "\n";
        }
        else
        {
            double ang=acos((dis*dis+r1*r1-r2*r2)/(2*dis*r1));
            double xe,ye;
            xe=(x2-x1)*r1/dis;
            ye=(y2-y1)*r1/dis;
           // cout << xe << " " << ye << "\n";
            pair<double, double> p=rotate(xe,ye,ang);
            vector<pair<double, double> > v;
            p.first+=x1;
            p.second+=y1;
            if(fabs(p.first)<.0004)
                p.first= MN;
            if(fabs(p.second)<.0004)
                p.second=MN;
            v.push_back(p);
            p=rotate(xe,ye,-ang);
            p.first+=x1;
            p.second+=y1;
            if(fabs(p.first)<.0004)
                p.first= MN;
            if(fabs(p.second)<.0004)
                p.second=MN;
            v.push_back(p);
            sort(v.begin(), v.end());
           // cout << v[1].second << "\n";
            cout << fixed << setprecision(3) << "(" <<  v[0].first << "," << v[0].second << ")" << "(" <<  v[1].first << "," << v[1].second << ")\n";
        }
    }
    return 0;
}