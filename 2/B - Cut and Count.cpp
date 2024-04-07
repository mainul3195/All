#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	vector<int> found(27,0);
	int count, ans=0;
	for(int i=1; i<n; i++)
	{
		fill(found.begin(), found.end(), 0);
		count=0;
		for(int j=0; j<i; j++)
				found[s[j]-97]=1;
		for(int j=i; j<n; j++)
			if(found[s[j]-97]==1)
			{
				found[s[j]-97]=2;
				count++;
			}
		ans=max(ans, count);
	}
	cout << ans << "\n";
	return 0;
}