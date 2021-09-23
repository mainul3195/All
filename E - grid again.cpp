#include<bits/stdc++.h>
using namespace std;
char s[1001][1001];
void execute();
int main()
{
	int t;
	cin >> t;
	while(t--)
		execute();
	return 0;
}
void execute()
{
	int n;
	cin >> n;
	int i,j;
	for(i=0; i<n; i++)
		scanf("%s", s[i]);
	int count = 0;
	for(i=0; i<n; i++)
		for(j=n-1; j>=0; j--)
		{
			if(s[i][j]=='#')
				break;
			s[i][j]=1;
		}
	for(i=0; i<n; i++)
		for(j=n-1; j>=0; j--)
		{
			if(s[j][i]=='#')
				break;
			if(s[j][i]==1)
				s[j][i]=2;
		}
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			if(s[i][j]==2)count++;
	cout << count << "\n";
	return;
}