#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    long  long n, m;
    cin >>  n >> m;
    if(2*n>=m)
        cout << m/2 << "\n";
    else 
        cout << n+(m-2*n)/4 << "\n";
    return 0;
}