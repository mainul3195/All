#include<bits/stdc++.h>
using namespace std;
void execute();
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		execute();
	return 0;
}
void execute()
{
	string a,b;
	cin >> a >> b;
	int i;
	for(i=0; a[i]; i++)
	{
		if(a[i]!='?' && b[i]!='?' && a[i] != b[i] )
		{
			cout << "No\n";
			return ;
		}
	}
	cout << "Yes\n";
	return ;
}