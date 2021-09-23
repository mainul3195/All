#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m;
	cin >> n >> m;
	vector <int> v(n+1, 0),track(n+1, 0);
	int i,j,k,flag=1;
	cin >> j;
	for(i=1; i<m; i++)
	{
		cin >>  k;
		if(k>j)
		{
			if(!v[j])
				track[k-j]++;
			else if(v[j] != k-j)
				flag=0;
			v[j]=k-j;
		}
		else
		{
			if(!v[j])
				track[n-j+k]++;
			else if(v[j] != n+k-j)
				flag=0;
			v[j]=n-j+k;
		}
		j=k;
	}
	
	// for(i=0; i<=n; i++)
	// 	cout << track[i] << " " << v[i]<< "\n";
	
	int sum=0;
	for(i=1; i<=n; i++)
	{
		if(track[i]>1 || !flag)
		{
			cout << "-1\n";
			return 0;
		}
	}
	for(i=1, j=1; i<=n && j<=n;)
	{
		if(!track[j])
		{
			if(!v[i])
			{
				track[j]+=1;
				v[i++]=j++;
			}
			else
				i++;
		}
		else
			j++;
	}
	for(i=1; i<=n; i++)
		cout << v[i]  << " \n"[i==n];
	
	return 0;
}