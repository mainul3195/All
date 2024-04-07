#include<bits/stdc++.h>
using namespace std;
int a[100000], prime[100000];
void execute();
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,i,j,k,l;
	for(i=3; i<316; i+=2)
		if(!a[i])
			for(j=i*i; j<100000; j+=2*i)
				a[j]=1;
	int count=0;
	prime[count++]=2;
	for(i=3; i<100000; i+=2)
		if(!a[i]) prime[count++]=i;
	cin >> n;
	while(n--)
		execute();
	return 0;
}
void execute()
{
	int n,a=0,b,c,i;
	cin>>n;
	for(i=0; prime[i]<31622; i++)
	{
		if(!(n%prime[i]))
		{
			a=n/prime[i];
			b=n-a;
			break;
		}
	}
	if(!a)
		a=1, b=n-1;
	cout << a << " " << b << "\n";
	return;
}