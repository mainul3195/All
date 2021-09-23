#include<bits/stdc++.h>
using namespace std;
int visited[100000],a[6], prime[100], no_of_prime, pd[10];
void sieve();
int prm_div(int);
int main()
{
	sieve();
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m,nop,i;
	cin >> n >> m;
	char sign;
	while(m--)
	{

		int target;
		cin >> sign >> target;
		/*
				cout << sign << target <<"\n";
		for(i=0; i<=10; i++)
			cout<<visited[i]<<" ";
		cout << "\n";
		*/
		if(target==1)
		{
			if(sign=='+')
			{
				if(!visited[1])
				{
					cout << "Success\n";
					visited[1]=1;
				}
				else
					cout << "Already on\n";
			}
			else
			{
				if(!visited[1])
					cout << "Already off\n";
				else
				{
					cout << "Success\n";
					visited[1]=0;
				}
			}
			continue;
		}
		nop = prm_div(target);
		if(sign == '+')
		{
			int flag=1;
			for(i=0; i<nop; i++)
			{
				if(visited[pd[i]])
				{
					if(visited[pd[i]]==target)
					{
						cout << "Already on\n";
						flag=0;
						break;
					}
					cout << "Conflict with " << visited[pd[i]] << "\n";
					flag=0;
					break;
				}
			}
			if(flag)
			{
				cout << "Success\n";
				for(i=0; i<nop; i++)
					visited[pd[i]] = target;
				visited[target]=target;			
			}
		}
		else
		{
			if(visited[target]!=target)
			{
				cout << "Already off\n";
				continue;
			}
			else
			{
				cout << "Success\n";
				for(i=0; i<nop; i++)
					visited[pd[i]]=0;
				visited[target]=0;
			}
		}
		/*
		for(i=0; i<=10; i++)
			cout<<visited[i]<<" ";
		cout << "\n";
		*/
	}
	return 0;
}
void sieve()
{
	int i,j,p,q;
	prime[no_of_prime++]=2;
	for(i=3; i<=19; i+=2)
	{
		p=i/64;
		q=((i+1)/2)%32;
		if(!(a[p] & 1<<q))
			for(j=i*i; j<=384; j+=2*i)
			{
				p=j/64;
				q=((j+1)/2)%32;
				a[p] |= 1<<q;
			}
	}
	for(i=3; i<=384; i+=2)
	{
		p=i/64;
		q=((i+1)/2)%32;
		if(!(a[p] & 1<<q))
			prime[no_of_prime++]=i;
	}
	return;
}
int prm_div(int n)
{
	int i,j,k,limit;
	for(i=0; i<10; i++)
		pd[i]=0;//cleaning previous value
	i=j=0;
	limit = sqrt(n);		
	while(n!=1 && prime[i]<=limit)
	{
		if(!(n%prime[i]))
		{
			pd[j++]=prime[i];
			while(!(n%prime[i]))
				n /= prime[i];
		}
		i++;
	}
	if(n!=1)
		pd[j++]=n;
	return j;
}