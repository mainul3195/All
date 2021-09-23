#include <bits/stdc++.h>
using namespace std;
void execute();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        execute();
    return 0;
}
void execute()
{
	int dif,n,n2=0,n3=0;
	cin>>n;
	if(n==1) 
        cout<<"0\n";
    else if(n%3)
        cout<<"-1\n";
    else
    {
        while(!(n%2))
        {
            n2++;
            n/=2;
        }
        while(!(n%3))
        {
            n3++;
            n/=3;
        }
        if(n>1 || n2>n3) 
            cout<<"-1\n";
        else
        {
            dif=n3+n3-n2;
            cout<<dif<<"\n";         
        }
               
    }
    
    return;
}