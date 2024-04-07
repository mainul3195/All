#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--){
    long long n, m, x;
    cin >> n >> m >> x;
    long long col = (x+n-1)/n, row = x%n;
    if(!row)
        row = n;
    cout << (row - 1)*m + col << "\n";
    }
    return 0;
}