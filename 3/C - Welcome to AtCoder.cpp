#include<iostream>
#include<map>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	map<int, int> mp;
	string s;
	int k;
	int acc=0, pc=0;
	for(int i=0; i<m; i++)
	{
		cin >> k >> s;
		if(mp[k] == -1)
			continue;
		if(s=="AC")
		{
			pc+=mp[k];
			acc++;
			mp[k]=-1;
		}
		else if(s=="WA")
			mp[k]++;
	}
	cout << acc << " " << pc << "\n";
	return 0;
}