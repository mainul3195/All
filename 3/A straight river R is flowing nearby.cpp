#include<bits/stdc++.h>
using namespace std;
#define MN 1e-8
double h,l,r,k;
double time(double x)
{
    return sqrt(x*x+h*h)/k + sqrt(r*r - 2*r*x + x*x + l*l);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    while(cin >> h >> l >> r >> k and (h or l or r))
    {
        double left=0, right=r,mid;

        while(right-left>1e-6)
        {
            mid=(left+right)/2;
            if(time(mid+MN)-time(mid)>0)
                right = mid;
            else 
                left = mid;
        }
        cout << setprecision(5) << sqrt(mid*mid+h*h) + sqrt(r*r - 2*r*mid + mid*mid + l*l) << "\n";
    }
    return 0;
}