#include<bits/stdc++.h>
using namespace std;
vector<int> ar(1005, 1);
void sod()
{
	for(int i=2; i<=1000; i++)
		for(int j=i; j<=1000; j+=i)
			ar[j]+=i;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	sod();
	int n;
	int j=0;
	while(cin >> n)
	{
		if(!n)
			return 0;
		int flag=0,i;
		for(i=1000; i>=1; i--)
			if(ar[i]==n)
			{
				flag=1;
				break;
			}
		cout<< "Case " << ++j << ": ";
		if(flag)
			cout << i << "\n";
		else
			cout << "-1\n";
	}
}