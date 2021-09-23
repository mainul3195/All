#include<bits/stdc++.h>
using namespace std;
int track[600];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	char a[1005];
	int count=0,i,j=0,k=1;
	cin >> a;
	for(i=0; a[i]; i++)
	{
		if(a[i]=='L')
			j++;
		else
			j--;
		if(j==0)
		{
			track[k++]=i;
			count++;
		}
	}
	cout << count << "\n";
	for(i=0, j=1; a[i]; i++)
	{
		cout << a[i];
		if(i==track[j])
		{
			cout << "\n";
			j++;
		}
	}
	return 0;
}