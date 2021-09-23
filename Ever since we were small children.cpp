#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<utility>
#define MN 1e-9
using namespace std;
// struct pig{
//     long double a, b, c;

//     void inp()
//     {
//         vector<long double> v(3);
//         for(int i=0; i<3; i++)
//             cin >> v[i];
//         sort(v.begin(), v.end());
//         c=v[0];
//         b=v[1];
//         a=v[2];
//     }
// };


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m;
    cin >> m;
    vector<long double> holes(m);


    for(int i=0; i<m; i++)
        cin >> holes[i];


    int n;
    cin >> n;


    for(int i=0; i<n; i++)
    {
        // pig pg;
        // pg.inp();
        long double pga, pgb, pgc;
        cin >> pga >> pgb >> pgc;
        if(pga<pgb)
        swap(pga, pgb);
        if(pga<pgc)
        swap(pga, pgc);
        //precalculation for finding angle
        //long double x=(pg.b*pg.b+pg.c*pg.c-pg.a*pg.a)/(2*pg.b*pg.c);


        //applying sine rule
        //long double R=pg.a/sqrt(1-x*x);

        long double s=(pga+pgb+pgc)/2;
        long double area=sqrt(s*(s-pga)*(s-pgb)*(s-pgc));
        long double R;
        //checking for obtuse angle (or right angle)
        if(pgb*pgb+pgc*pgc-pga*pga< MN)
            R=pga;
        else 
            R=(pga*pgb*pgc)/(2*area);

        vector<int> ind;
        for(int j=0; j<holes.size(); j++)
            if(R-holes[j]<MN)//if our required diameter is less or equal to given diameter then ok
                ind.push_back(j+1);

        //output section
        cout << "Peg " << (char)(i+65) << " will ";
        if(ind.size())
        {
            cout << "fit into hole(s): ";
            for(int j=0; j<ind.size(); j++)
                cout << ind[j] << " \n"[j+1==ind.size()];
        }
        else 
            cout << "not fit into any holes\n";
    }
    return 0;
}