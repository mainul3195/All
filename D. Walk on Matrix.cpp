#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k;
    cin >> k;
    cout << "2 3\n";
    cout << (1<<17) + k << " " << (1<<17) << " 0\n";
    cout << k << " " << (1<<17) +k << " " << k << "\n";
    return 0;
}