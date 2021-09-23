#include<bits/stdc++.h>
using namespace std;
struct pt
{
    double x,y;
    void input()
    {
        cin >> x >> y;
    }
    void output()
    {
        cout << x << " " << y << "\n";
    }
    pt operator - (const pt &a)
    {
        return {x-a.x, y-a.y};
    }
    double operator * (const pt &a)
    {
        return sqrt((x-a.x)*(x-a.x)+(y-a.y)*(y-a.y));
    }
    double operator & (const pt &a)
    {
        return fabs(x*a.y - y*a.x);
    }
};
double area(pt a, pt b, pt c)
{
    return (.5*((b-a)&(c-a)));
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    pt a, b, c;
    a.input();
    b.input();
    c.input();
    pt an, af, bn, bf, cn, cf;
    int n,h;
    cin >> n >> h;
    double dis= a*b;
    an.x=(h*b.x+(dis-h)*a.x)/dis;
    an.y=(h*b.y+(dis-h)*a.y)/dis;
    for(int i=0; i+1<n; i++) cin >> h;
    af.x=(h*b.x+(dis-h)*a.x)/dis;
    af.y=(h*b.y+(dis-h)*a.y)/dis;

    cin >> n >> h;
    dis= c*b;
    bn.x=(h*c.x+(dis-h)*b.x)/dis;
    bn.y=(h*c.y+(dis-h)*b.y)/dis;
    for(int i=0; i+1<n; i++) cin >> h;
    bf.x=(h*c.x+(dis-h)*b.x)/dis;
    bf.y=(h*c.y+(dis-h)*b.y)/dis;

    cin >> n >> h;
    dis= c*a;
    cn.x=(h*a.x+(dis-h)*c.x)/dis;
    cn.y=(h*a.y+(dis-h)*c.y)/dis;
    for(int i=0; i+1<n; i++) cin >> h;
    cf.x=(h*a.x+(dis-h)*c.x)/dis;
    cf.y=(h*a.y+(dis-h)*c.y)/dis;

    vector<pt> ar(6);
    ar[0]=an;
    ar[1]=af;
    ar[2]=bn;
    ar[3]=bf;
    ar[4]=cn;
    ar[5]=cf;
    double mx=-1, khetrofol;
    for(int i=0; i+2<6; i++)
        for(int j=i+1; j+1<6; j++)
            for(int k=j+1; k<6; k++)
                mx = max (mx, area(ar[i], ar[j], ar[k]));    

    cout << fixed << setprecision(9) << mx << "\n";
    return 0;
}