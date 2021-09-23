#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    int tc=0;
    while(t--)
    {
        int a, b;
        char c;
        cin >> a >> c >> b;
        double l=0, r=201, mid;
        double len, wd;
        while(fabs(l-r)>1e-11)
        {
            mid=(l+r)/2;
            len=mid;
            wd = b*len/a;
            double rad=sqrt(len*len + wd*wd)/2;
            double theta = acos((2*rad*rad-wd*wd)/(2*rad*rad));
            double chap = rad*theta;
            double perimtre = 2*(len+chap);
            if(perimtre>400)
                r=mid;
            else 
                l=mid;
        }
        cout << fixed << setprecision(8) <<  "Case " << ++tc << ": " << len << " " << wd << "\n";
    }
    return 0;
}