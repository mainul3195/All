#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
#define MN 1e-7
int main()
{
    int t;
    cin >> t;
    cout << "INTERSECTING LINES OUTPUT\n";
    while(t--)
    {
        double x1,x2,x3,x4,y1,y2,y3,y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        if(fabs((y1-y2)*(x4-x3)-(x2-x1)*(y3-y4))<MN)
        {
            if(fabs((x2-x1)*(y4-y1)-(x4-x1)*(y2-y1))<MN)
                cout << "LINE\n";
            else 
                cout << "NONE\n";
            continue;
        }
        cout << "POINT ";
        cout << fixed << setprecision(2) << ((x2-x1)*(x3*y4-x4*y3)-(x4-x3)*(x1*y2-x2*y1))/((y1-y2)*(x4-x3)-(x2-x1)*(y3-y4)) << " " << ((y3-y4)*(x1*y2-x2*y1)-(y1-y2)*(x3*y4-x4*y3))/((y1-y2)*(x4-x3)-(x2-x1)*(y3-y4)) << "\n";
    }
    cout << "END OF OUTPUT";
    return 0;
}