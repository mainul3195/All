#include<bits/stdc++.h>
using namespace std;
int main()
{
	//ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long i=0,t;
	cin >> t;
	while(t--)
	{
		string a;
		long long remainder=0, dividor;
		cin >> a >> dividor;
		if(dividor<0)
			dividor*=-1;
		//cout << a << " " << dividor << "\n";
		long long start=-1, end=a.size();
		if(a[0]=='-')
			start++;

		while(start<end)
		{
			if(remainder<dividor && ++start<end)
			{
				remainder = remainder*10 + (a[start]-'0');
				continue;
			}
			remainder%=dividor;
		}
		cout << "Case " << ++i << ": ";
		if(remainder)
			cout << "not divisible\n";
		else
			cout << "divisible\n";
	}
	return 0;
}