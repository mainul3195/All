#include<bits/stdc++.h>
using namespace std;
void execute();
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	while(n--)
		execute();
	return 0;
}
void execute()
{
	int n,a=10000,b,c,i,d,in1,in2,in3,j=0,tmp=0;
	in1=in2=in3=-1;
	cin >> n;
	for(i=1; i<=n; i++)
	{
		cin >> d;
		if(tmp)
			continue;
		if(j==0)
		{
			if(d<a) 
			{
				a=d;
				in1=i;
				j=1;
			}
		}
		else if(j==1)
		{
			if(d>a)
			{
				b=d;
				in2=i;
				j=2;
			}
			else if(d<a)
			{
				a=d;
				in1=i;
			}
		}
		else
		{
			if(d<b)
			{
				c=d;
				in3=i;
				tmp=1;
			}
			else if(d>b)
			{
				b=d;
				in2=i;
			}
		}
	}
	if(in3==-1)
		cout << "NO\n";
	else
		cout << "YES\n" << in1 << " " << in2 << " " << in3 << "\n";
	return;
}