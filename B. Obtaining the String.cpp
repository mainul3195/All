#include<bits/stdc++.h>
using namespace std;
string a, b;
int find(int l, int r, char t)
{
	for(int i=l; i<=r; i++)
		if(a[i]==t)
			return i;
	return 0;
}
void configure(int f, int to)
{
	char temp=a[f];
	for(int i=f-1; i>=to; i--)
		a[i+1]=a[i];
	a[to]=temp;
	return;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	cin >> a >> b;
	bool ok=1;
	vector<int> ans;
	for(int i=0; i<a.size(); i++)
		if(a[i] != b[i])
		{
			int pos=find(i+1, b.size()-1, b[i]);
			if(!pos)
			{
				ok=0;
				break;
			}
			configure(pos, i);
			for(int j=pos-1; j>=i; j--)
				ans.push_back(j);
		}
	if(!ok)
		cout << "-1\n";
	else
	{
		cout << ans.size() << "\n";
		for(int i=0; i<ans.size(); i++)
			cout << ans[i]+1 << " \n"[i==ans.size()-1];
	}
	return 0;
}