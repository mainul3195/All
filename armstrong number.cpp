#include <bits/stdc++.h>
using namespace std;
static int powr(int base, int power)
{
    int ans=1;
    while(power>0)
    {
        ans *= base;
        power--;
    }
    return ans;
}
int main()
{
    int num;
    cin >> num;
    if(num==0)
    {
        cout << "armstrong";
        return 0;
    }
    int number_of_digits=0, n=num, remainder, temp=0;
    while(n!=0)
    {
        number_of_digits ++;
        n = n/10;
    }
    n=num;
    for(int i=0; i<number_of_digits; i++)
    {
        remainder = n%10;
        n/=10;
        temp += powr(remainder, number_of_digits);
    }
    if(temp == num)
        cout << "Armstrong\n";
    else
    {
        cout << "Not Armstrong\n";
    }
}