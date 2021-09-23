#include<bits/stdc++.h>
using namespace std;
#define ckbit(x) ( t[(x)/64] & 1 << ((x)%64)/2)
#define cngbit(x) ( t[(x)/64] |= 1 << ((x)%64)/2)
int t[20];
vector<int>prime;
void sieve()
{
	prime.push_back(2);
	for(int i=3; i<=31; i+=2)
		if(!ckbit(i))
			for(int j=i*i; j<=1000; j+=2*i)
				if(!ckbit(j))
					cngbit(j);
	for(int i=3; i<=1000; i+=2)
		if(!ckbit(i))
			prime.push_back(i);
	return;
}
int prime_div(int n, vector<int> &v)
{
	int mx=0;
	for(int i=0; prime[i]*prime[i]<=n; i++)
	{
		int c=0;
		while(!(n%prime[i]))
		{
			c++;
			n/=prime[i];
		}
		if(c>v[prime[i]])
		{
			if(prime[i]>mx)
				mx=prime[i];
			v[prime[i]]=c;
		}
	}
	if(n!=1 && !v[n])
	{
		if(n>mx)
				mx=n;
		v[n]=1;
	}
	return mx;
}
int power(int a, int b)
{
	int x=1;
	while(b--)
		x*=a;
	return x;
}
char ans[1000000],mul[1000000];
int main()
{
	sieve();
	int tc,i=0;
	cin >> tc;
	while(tc--)
	{
		for(int j=0; ans[j]; j++)
			ans[j]=0;
		ans[0]='1';
		int n;
		int mx=0;
		cin >> n;
		vector<int>p(10005, 0);
		for(int j=0; j<n; j++)
		{
			int k;
			cin >> k;
			mx=max(mx, prime_div(k, p));
		}
		// for(int j=2; j<=10; j++)
		// 	cout << j << " = " << p[j] << "\n";
		//cout << mx << "\n";
		for(int j=2; j<=mx; j++)
			if(p[j])
			{
				int nm=power(j, p[j]);
				for(int a=0; ans[a]; a++)
				{
					int num=nm*(ans[a]-48);
					int car=0;
					int start=a;
				//	cout << nm << " " << ans <<  " " <<  num <<"\n";
					do
					{
					//	cout << "__" << mul << "\n";
						int r=num%10;
						num/=10;
						int tmp=0;
						if(mul[start])
							tmp=mul[start]-48;
						int sum=r+tmp+car;
						car=sum/10;
						sum%=10;
						mul[start++]=sum+48;
					}while(num || car);
					//cout << "\t" << mul << "\n";
				}
				//cout << "\n";
				int b;
				for(b=0; mul[b]; b++)
				{
					ans[b]=mul[b];
					mul[b]=0;
				}
				ans[b]=0;
				//cout << "b= " << b << "\n";
			}
		int j=0;
		while(ans[++j]);
		reverse(ans, ans+j);
		cout << "Case " << ++i<< ": " << ans << "\n";
	}
	return 0;
}