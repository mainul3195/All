#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,i,j,k;
	string s;
	cin >> n >> s;
	char Key[] = "PgEfTYaWGHjDAmxQqFLRpCJBownyUKZXkbvzIdshurMilNSVOtec#@_!=.+-*/",Original[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	if(n==1)
	{
		for(i=0; s[i]; i++)
		{
			for(j=0; Original[j]!=s[i]; j++);
			cout << Key[j];
		}
	}
	else
	{
		for(i=0; s[i]; i++)
		{
			for(j=0; Key[j]!=s[i]; j++);
			cout << Original[j];
		}
	}
	return 0;
}