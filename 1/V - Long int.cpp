#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, i, k;
	string t,s;
	cin >> n >> k >> s;
	t=s;
	for(i=k; i<n; i++)
		t[i]=t[i-k];

	if(t<s)
	{
		for(i=k-1; i>=0; i--)
		{
			if(t[i]!='9')
			{
				t[i]++;
				break;
			}	
			else
				t[i]='0';		
		}
		for(i=k; i<n; i++)
			t[i]=t[i-k];
		cout << n << "\n" << t;
	}
	else
		cout << n << "\n" << t;
	return 0;
}