#include<bits/stdc++.h>
using namespace std;
#define  ld long double
#define MN 1e-10
struct pt
{
    ld x,y;
    void input()
    {
        cin >> x >> y;
    }
    ld operator & (const pt &a)
    {
        return (x*a.y-y*a.x);
    }
};
ld nCr[2505][2505]={0};
void calc_nCr(int n, int r)
{
    for(int i=1; i<=n; i++)
        for(int j=0; j<=i; j++)
        {
            if(i==j or !j)
                nCr[i][j]=1;
            else 
                nCr[i][j]= nCr[i-1][j-1] + nCr[i-1][j];
        }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    calc_nCr(n+1, k+1);
    // for(int i=1; i<=n; i++)
    //     for(int j=1; j<=i; j++)
    //         cout << i << "C" << j << "= " <<nCr[i][j] << "\n";
    vector<pt> point(n);
    for(int i=0; i<n; i++)
        point[i].input();
    ld totarea=0.0;
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
        {
            totarea += (point[i]&point[j])*nCr[n-j-1][k-2];
            cout << i << " " << j << "\n";
        }
    totarea/=2.0*nCr[n][k];
    cout << fixed << setprecision(9) << totarea << "\n";
    return 0;
}