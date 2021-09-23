#include<bits/stdc++.h>
using namespace std;
bool ckprime(int n)
{
	if(n==2)
		return 1;
	if(!(n%2))
		return 0;
	int l=sqrt(n);
	for(int i=3; i<=l; i+=2)
		if(!(n%i))
			return 0;
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	while(cin >> s)
	{
		int i,j,n=0;
		for(i=0; s[i]; i++)
		{
			if(s[i]>='a' && s[i]<='z')
				n+=s[i]-96;
			else
				n+=s[i]-65 + 27;
		}
		s.clear();
		//cout << n << "\n";
		if(ckprime(n))
			cout << "It is a prime word.\n";
		else
			cout << "It is not a prime word.\n";
	}
	return 0;
}