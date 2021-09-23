#include<iostream>
#include<vector>
using namespace std;
struct point
{
    int x,y;
    void inp()
    {
        cin >> x >> y;
    }
};
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<point> student(n), ckpoint(m);
    for(int i=0; i<n; i++)
        student[i].inp();
    for(int i=0; i<m; i++)
        ckpoint[i].inp();
    vector<int>nearest(n);
    for(int i=0; i<n; i++)
    {
        int mn=1000000000;
        int ind;
        for(int j=0; j<m; j++)
            if(abs(student[i].x-ckpoint[j].x)+abs(student[i].y-ckpoint[j].y)<mn)
            {
                mn=abs(student[i].x-ckpoint[j].x)+abs(student[i].y-ckpoint[j].y);
                ind=j;
            }
        nearest[i]=ind;
    }
    for(int i=0; i<n; i++)
        cout << nearest[i] +1  << "\n";
    return 0;
}