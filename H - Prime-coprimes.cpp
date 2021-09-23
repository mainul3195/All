#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int test=0,a[3200], vst[100200],prime[100000];
void sieve();
void execute();
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,m,i;
	cin>>n>>m;
	sieve();
	while(m--)
		execute();
	return 0;
}
void execute()
{
	char c;
	int n,pd[30]={0},i,j=-1,lim,temp;
	cin>> c >> n;
	//cout << c << " " << n << "\n";
	temp=n;
	lim = sqrt(n);
	for(i=0;prime[i]<=lim && n>1; i++)
	{
		if(!(n%prime[i]))
		{
			pd[++j]=prime[i];
			while(!(n%prime[i]) && n>1)
				n/=prime[i];
		}
	}
	if(n!=1)pd[++j]=n;
//	cout << "pd[0] = " << pd[0] <<"\n";
	if(c=='+')
	{
		if(vst[temp]==temp)
			cout << "Already on\n";
		else
		{
			int flag=0;
			for(i=0; pd[i]; i++)
				if(vst[pd[i]])
				{
					flag=vst[pd[i]];
					break;
				}
			if(flag)
				cout << "Conflict with " <<flag<<"\n";
			else
			{
				cout << "Success\n";
				for(i=0; pd[i]; i++)
					vst[pd[i]]=temp;
				vst[temp]=temp;
			}			
		}
		
	}
	else
	{
		if((vst[temp])!=temp)
			cout << "Already off\n";
		else
		{
			for(i=0; pd[i]; i++)
				vst[pd[i]]=0;
			vst[temp]=0;
			cout << "Success\n";
		}
	}
	/*
	++test;
	cout << "case "<< test<< "\n" << c << " " << temp<< "\n";
	cout << "pd = ";
	cout << pd[0] << " " << pd[1]<< " "<< pd[2] << "\n";
	cout<<"vst =";
	for (i=0; i<=3; i++)
		cout << vst[i]<<" ";
	cout<<"\n\n\n";
	*/
}
void sieve()
{
	int i,j,k,l;
	for(i=3; i<=316; i+=2)
	{
		k=i/32;
		l=i%32;
		if(!(a[k] & 1<<l))
			for(j=i*i; j<=100199; j+=2*i)
			{
				k=j/32;
				l=j%32;
				a[k] |= 1<<l;
			}
	}
	j=0;
	prime[j++]=2;
	for(i=3; i<=100199; i+=2)
	{
		k=i/32;
		l=i%32;
		if(!(a[k] & 1<<l))
			prime[j++]=i;
	}
}