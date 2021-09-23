#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int countodd=0, counteven=0, count4=0;
    for(int i=0; i<n; i++)
    {
        int j;
        cin >> j;
        if(!(j%4))
            count4 ++;
        else if(j%2)
            countodd ++;
        else 
            counteven ++;
    }
    if((!counteven && countodd <= count4 +1 ) || (counteven && countodd <= count4))
        cout << "Yes\n";
    else 
        cout << "No\n";
    return 0;
}