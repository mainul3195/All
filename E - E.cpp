#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	int mx=0;
	string a;
	for(int i=0; i+1<n; i++)
	{
		int count=0;
		for(int j=0; j+1<n; j++)
			if(!s.compare(i,2, s, j, 2))
				count++;
		if(count>mx)
		{
			mx=count;
			a=s.substr(i,2);
		}
	}
	cout << a << "\n";
	return 0;
}