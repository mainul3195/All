#include<iostream>
#include<vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<int> vis(n+1, 0), v(n+1);
	for(int i=1; i<=n; i++)
		cin >> v[i];
	int count=0;
	bool ok=1;
	int s=1;;
	while(1)
	{
		count++;
		if(vis[s])
		{
			ok=0;
			break;
		}
		vis[s]=1;
		s=v[s];
		if(s==2)
			break;
	}
	if(ok)
		cout << count << "\n";
	else
		cout << "-1";
	return 0;
}