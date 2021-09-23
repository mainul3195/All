#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s;
	int n=s.size();
	int ans=0;
	for(int i=0; i<n-1; i++)
		for(int j=1; 2*j + i<s.size(); j++)
		{
			if(!s.compare(i, j, s, i+j, j))
				if(2*j!=n)
					ans=max(ans, 2*j);
		}
	cout << ans << "\n";
	return 0;
}