#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,i;
	cin  >> n;
	int lim=n/2;
	for(i=0; i<lim; i++)
	{
		if(i%2)
			cout << "bb";
		else
			cout << "aa";
	}
	if(n%2)
	{
		if(i%2)
			cout << "b";
		else
			cout << "a";
	}
	return 0;
}