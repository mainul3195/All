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
	int x,y,n,m,j;
	cin>>x>>y>>n;
	m=n/x;
	j=m*x+y;
	if(j>n) j-=x;
	cout<<j<<"\n";
    return;
}