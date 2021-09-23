#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    if((n+1)/2 >= k)
        cout << "YES\n";
    else 
        cout << "NO\n";
    return 0;
}