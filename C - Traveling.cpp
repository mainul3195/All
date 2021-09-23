#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int t=0;
    int dis=0;
    bool ok=1;
    for(int i=0; i<n; i++)
    {
        int x,y,tmd;
        cin >> tmd >> x >> y;
        int tempdis= abs(x+y-dis);
        dis = x+y;
        int time = tmd-t;
        t=tmd;
        if(tempdis > time || tempdis%2 != time%2)
        {
            cout << "No\n";
            ok=0;
            break;
        }
    }
    if(ok)
        cout << "Yes\n";
    return 0;
}