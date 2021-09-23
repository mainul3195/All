#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	vector<long long> mul;
	mul.push_back(1);
	for(int i=0; i<33; i++)
		mul.push_back(mul[i] << 1);
	cin >> t;
	string s;
	while(t--)
	{
		int n,k;
		cin >> n >> k;
		int i=26;

		if(n>k)
		{
			cout << "-1\n";
			continue;
		}
		else
		{
			while(n)
			{
				for(; k-mul[i]<n-1 || mul[i]>k; i--);
				k-=mul[i];
				s=(char)(97+i) +s;
				n--;
			}
			if(k)
				cout << "-1\n";
			else
				cout << s << "\n";
		}
		s.clear();
	}
	return 0;
}