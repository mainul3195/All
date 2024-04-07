#include<iostream>
using namespace std;
long long gcd(long long a, long long b)
{
    if(b==0)
        return a;
    return gcd(b, a%b);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    long long lcm = (c*d)/gcd(c, d);
    cout << b-a+1-(b/c-(a-1)/c + b/d-(a-1)/d  - b/lcm+(a-1)/lcm) << "\n";
    return 0;
}