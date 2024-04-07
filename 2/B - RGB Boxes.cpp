#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int r,g, b, n;
    cin >> r >> g >> b >> n;
    int count = 0;
    for(int i=0; i*r<=n; i++)
        for(int j=0; i*r + j*g <=n; j++)
            if(!((n-i*r-j*g)%b))
                count ++;
    cout << count << "\n";
    return 0;
}