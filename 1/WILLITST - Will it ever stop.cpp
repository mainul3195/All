#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long n;
    cin >> n;
    if(n == (n&(-n))) cout << "TAK\n";
    else cout << "NIE\n";
    return 0;
}