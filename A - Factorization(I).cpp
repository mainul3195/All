#include<bits/stdc++.h>
using namespace std;
vector<int>pf;
void find_Factor(int n)
{
	pf.push_back(1);
	while(!(n%2))
	{
		pf.push_back(2);
		n/=2;
	}
	for(int i=3; i*i<=n; i+=2)
		while(!(n%i))
		{
			pf.push_back(i);
			n/=i;
		}
	if(n!=1)
		pf.push_back(n);
	return;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	while(cin >> n)
	{
		find_Factor(n);
		for(int i=0; i<pf.size(); i++)
		{
			cout << pf[i];
			if(i==pf.size()-1)
				cout << "\n";
			else
				cout << " x ";
		}
		pf.clear();
	}
	return 0;
}