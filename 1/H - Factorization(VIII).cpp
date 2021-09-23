#include<bits/stdc++.h>
using namespace std;
void execute(int);
int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0);
	int t,i=0;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		cout << "Case " << ++i << ": " << n << " = ";
		execute(n);
	}
	return 0;
}

void execute(int n)
{
	map<int,int>mp;
	for(int i=2; i<=n; i++)
	{
		int c=0;
		int j=i;
		while(!(j&1))
		{
			c++;
			j>>=1;
		}
		if(c)		
			mp[2]+=c;
		for(int k=3; k*k<=j; k+=2)
		{
			c=0;
			while(!(j%k))
			{
				c++;
				j/=k;
			}
			if(c)
				mp[k]+=c;
		}
		if(j!=1)
			mp[j]++;
	}
	for(auto it=mp.begin(); it!=mp.end(); it++)
	{
		cout << it->first << " (" << it->second << ")";
		auto i=it;
		i++;
		if(i==mp.end())
			cout << "\n";
		else
			cout << " * ";
	}
	return;
}