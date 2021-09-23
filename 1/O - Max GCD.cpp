#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
	if(!b)
		return a;
	return gcd(b, a%b);
}
int main()
{
	int n;
	string a;
	cin >> n;
	getline(cin, a);
	while(n--)
	{
		getline(cin , a);
		vector<int>v;
		stringstream s(a);
		int i;
		while(s >> i)
			v.push_back(i);
		int l=v.size(),Gcd,mx=0;
		for(i=0; i<l; i++)
			for(int j=i+1; j<l; j++)
			{
				Gcd=gcd(v[i], v[j]);
				if(Gcd>mx)
					mx=Gcd;
			}
		cout << mx << "\n";
	}
	return 0;
}