#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base:: sync_with_stdio(0);cin.tie(0);
	int a[5]={0}, i,j;
	string s;
	cin>>s;
	for(i=0; s[i]; i++)
	{
		if(s[i]=='e'|| s[i]=='E')
			a[0]++;
		else if(s[i]=='g'|| s[i]=='G')
			a[1]++;
		else if(s[i]=='y'|| s[i]=='Y')
			a[2]++;
		else if(s[i]=='p'|| s[i]=='P')
			a[3]++;
		else if(s[i]=='t'|| s[i]=='T')
			a[4]++;
	}
	for(i=1, j=a[0]; i<5; i++)
		if(a[i]<j)
			j=a[i];
	cout << j;
	return 0;
}