#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, p;
    cin >> n >> p;
    int odd_count = 0, even_count = 0;
    for(int i=0; i<n; i++)
    {
        int j;
        cin >> j;

        if(j%2)
            odd_count++;
        else 
            even_count ++;
    }

    if(odd_count)
        cout << (1ll<<(n-1)) << "\n";
    else
    {
        if(p) cout << "0\n";
        else cout << (1ll<<n) << "\n";
    }
    return 0;
}