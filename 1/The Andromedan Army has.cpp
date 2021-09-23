#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    double x1,y1,x2,y2,x3,y3;
    while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)
    {
        if(fabs(0-.5*(x1*y2 + x2*y3 + x3*y1 - x2*y1 - x3*y2 - x1*y3)) < .00000001)
        {
            cout << "Impossible\n";
            continue;
        }
        double x= ((y1-y2)*(x3*x3-x2*x2+y3*y3-y2*y2)+(y2-y3)*(x1*x1 + y1*y1 -x2*x2 - y2*y2))/(2*((x1-x2)*(y2-y3) - (y1-y2)*(x2-x3))) ;
        double y=  ((x2-x3)*(x2*x2-x1*x1+y2*y2-y1*y1)+(x1-x2)*(x2*x2 + y2*y2 -x3*x3 - y3*y3))/(2*((x1-x2)*(y2-y3) - (y1-y2)*(x2-x3)));
        if(fabs(0-x) < .00000001)
            x=0;
        if(fabs(0-y) < .00000001)
            y=0;
        cout << setprecision(8) <<  x << " " << y << "\n";
    }
    return 0;
}