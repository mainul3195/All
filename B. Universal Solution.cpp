#include<bits/stdc++.h>
using namespace std;
void execute();
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	while(n--)
		execute();
	return 0;
}
void execute()
{
	string s;
	int i,a[3]={0},m=0,in=0,len=0;
	cin >> s;
	while(s[++len]);
	for (i=0; s[i]; i++)
	{
		if(s[i]=='R')
			a[0]++;
		else if(s[i]=='P')
			a[1]++;
		else a[2]++;
	}
	m=a[0];
	for(i=1; i<3; i++)
		if(a[i]>m)
		{
			m=a[i];
			in=i;
		}
	char c;
	if(in==0) c='P';
	else if(in==1) c='S';
	else c='R';
	for(i=0; i<len; i++)
		cout << c;
	cout << "\n";
	return;
}