#include<iostream>
using namespace std;
int main()
{
    int num[3][3];
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            cin >> num[i][j];
    bool ok=1;
    for(int i=1; i<3; i++)
    {
        if(num[i][0]-num[i-1][0]==num[i][1]-num[i-1][1] && num[i][0]-num[i-1][0]==num[i][2]-num[i-1][2])
            continue;
        ok=0;
        break;
    }
    for(int i=1; i<3; i++)
    {
        if(num[0][i]-num[0][i-1]==num[1][i]-num[1][i-1] && num[0][i]-num[0][i-1]==num[2][i]-num[2][i-1])
            continue;

        ok=0;
        break;
    }
    if(ok)
        cout << "Yes\n";
    else 
        cout << "No\n";
    return 0;
}