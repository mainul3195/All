#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, y;
    cin >> n >> y;
    y/=1000;
    bool ok=1;
    for(int i=0; i<=n; i++)
    {
        int a= 4*i + y - 5*n;
        int b= 10*n -y - 9*i;
        if(a>=0 && b>=0 && !(a%5) && !(b%5) && (a/5 <=n) && b/5<=n)
        {
            cout << a/5 << " " << b/5 << " " << i << "\n";
            ok=0;
            break;
        }
    }
    if(ok)
        cout << "-1 -1 -1\n";
    return 0;
}