#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	int count=0,i,j,n,a,dif;
	vector <int> v;
	cin >> n >> a;
	a--;
	for(i=0; i<n; i++)
	{
		cin >> j;
		v.push_back(j);
	}
	for(dif=0; a+dif<n && a-dif>=0; dif++)
		if(v[a+dif] && v[a-dif]) count +=2;
	if(v[a])count--;
	if(a+dif==n)
		for(i=0; i<=a-dif; i++)
		{
			if(v[i]) count++;
		}
	else if(a-dif==-1)
		for(i=a+dif; i<n; i++)
			if(v[i]) count++;
	cout << count <<"\n";

}