#include<bits/stdc++.h>
using namespace std;
struct pt
{
    int x,y;
    void input()
    {
        cin >> x >> y;
    }
    int operator & (const pt &a)
    {
        return (x*a.y-y*a.x);
    }
    pt operator - (const pt &a)
    {
        return {x-a.x, y-a.y};
    }
};
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<pt> point(n);
    int right_max=-1, up_max=-1, left_max=10000, down_max=10000;
    for(int i=0; i<n; i++)
        point[i].input();
    for(int i=0; i<n; i++)
    {
        pt a=point[i];
        pt b=point[(i+1)%n];
        pt c=point[(i+2)%n];
        pt d=point[(i+3)%n];
        pt ab=b-a;
        pt bc=c-b;
        pt cd=d-c;
        if((ab&bc) > 0 && (bc&cd)>0)
        {
            pt ba= a-b;
            if(ba.x<0 && cd.x<0)
                right_max= max(right_max, c.x);
            else if(ba.x>0 && cd.x>0)
                left_max=min(left_max, b.x);
            else if(ba.y<0 && cd.y <0)
                up_max=max(up_max, b.y);
            else if(ba.y>0 && cd.y>0)
                down_max=min(down_max, b.y);
        }
    }
    if(down_max<up_max || left_max<right_max)
        cout << "DANGER\n";
    else 
        cout << "SAFETY\n";
    return 0;
}