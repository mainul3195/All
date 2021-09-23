#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		int n,k;
		cin >> n >> k >> s;
		int no1=0, no0=0;
		bool flag=1;

		for(int i=0; i<k; i++)
		{
			if(s[i]=='1')
				no1++;
			else if(s[i]=='0')
				no0++;
		}
		if(no1<=k/2 && no0<=k/2)
		{
			int t1=no1,t0=no0;
			for(int i=k; i<n; i++)
			{
				if(s[i-k]=='0')
					t0--;
				else if(s[i-k]=='1')
					t1--;
				if(s[i]=='0')
					t0++;
				else if(s[i]=='1')
					t1++;
				if(t1>k/2 || t0>k/2)
				{
					flag=0;
					break;
				}
			}
			if(flag)
			{
				for(int i=k; i<n; i++)
				{
					if(no0==k/2)
						for(int l=i-1; l>=i-k; l--)
							if(s[l]=='?')
								s[l]='1';
					if(no1==k/2)
						for(int l=i-1; l>=i-k; l--)
							if(s[l]=='?')
								s[l]='0';
					if(s[i-k]=='0')
						no0--;
					else if(s[i-k]=='1')
						no1--;
					if(s[i]=='0')
						no0++;
					else if(s[i]=='1')
						no1++;
					if(s[i]=='?')
					{
						if(s[i-k]=='0')
							no0++;
						else if(s[i-k]=='1')
							no1++;
						s[i]=s[i-k];
					}
					else if(s[i-k]=='?')
					{
						if(s[i]=='0')
							no0--;
						else if(s[i]=='1')
							no1--;
						s[i-k]=s[i];
					}
					if(no1!=no0)
					{
						flag=0;
						break;
					}
				}
			}
			
		}
		else
			flag=0;
		if(flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}