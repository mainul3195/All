#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long n;
    cin >> n;
    cout <<  ((int)sqrt(1+8*(n-1))-1)/2 + 1 << "\n";
    return 0;
}