#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	int tc=0;
	while(t--)
	{
		int n,m;
		cin >> n >>m;
		string a, b, c;
		cin >> a >> b >> c;
		int dif;
		if(b[0]<a[0])
			dif=b[0]+26-a[0];
		else
			dif=b[0]-a[0];
		cout << "Case #" << ++tc << ": ";
		for(char ch:c)
			cout << (char)((ch-65-dif+26)%26 + 65) ;
		cout << "\n";
	}
	return 0;
}