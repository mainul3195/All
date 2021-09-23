#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int mn=101;
    int sum=0;
    for(int i=0; i<n; i++)
    {
        int j;
        cin >> j;
        //cout << j << "\n";
        sum+=j;
        if(j<mn && (j%10))
            mn=j;
    }
    //cout << sum << " " << mn << "\n";
    if(mn == 101)
        cout << "0\n";
    else if(sum%10)
        cout << sum << "\n";
    else 
        cout << sum-mn << "\n";
    return 0;
}