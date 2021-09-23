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
	int i,n,mc=0,bc=0;
    char s;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>s;
        if(s=='(') bc++;
        else bc--;
        if(bc<0)
        {
            mc++;
            bc++;
        }
    }
	cout<<bc<<"\n";
    return;
}