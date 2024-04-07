#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long n, a, b;
    cin >> n >> a >> b;
    if(a>b || (n==1 && a!=b))
        cout << "0\n";
    else
    {
        cout << a*(2-n) + b*(n-2) + 1 << "\n";
    }
    return 0;
}