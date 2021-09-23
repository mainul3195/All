#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    bool ok=1;
    for(int i=1; i<=b; i++)
        if((a*i)%b == c)
        {
            cout << "YES\n";
            ok=0;
            break;
        }
    if(ok)
        cout << "NO\n";
    return 0;
}