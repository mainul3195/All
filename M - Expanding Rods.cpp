#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, tc=0;
    cin >> t;
    while(t--)
    {
        cout << "Case " << ++ tc << ": ";
        double len, temp, cof;
        cin >> len >> temp >> cof;
        double exp_len = (1+temp*cof)*len;
        double l=0, r=len/2, h;
        while(fabs(r-l)>1e-10)
        {
            h=(r+l)/2;
            double c=len/2;
            double rad = .5*(c*c/h + h);
            double theta = exp_len/rad;
            double temp_len = 2*sin(theta/2)*rad;
            if(temp_len>len)
                l=h;
            else 
                r=h;
        }
        cout << fixed << setprecision(8) << l << "\n";
    }
    return 0;
}