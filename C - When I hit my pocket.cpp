#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long k, a, b;
    cin >> k >> a >> b;
    if(a>=b-2)
        cout << k+1 << "\n";
    else
    {
        long long bsc = 1;
        if(k>=a+1)
        {
            bsc = b;
            k-=a+1;
        }
        if(bsc>=a)
        {
            bsc += (k/2)*(b - a);
            bsc += k%2;
        }
        else
        {
            bsc += k;
        }
        
        cout << bsc << "\n";
    }
    return 0;
}