#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string c,s="abcdefghijklmnopqrstuvwxyz ";
	int k,t,n[] = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4,1};
	cin >> t;
	getline(cin,c);
	for(k=1; k<=t; k++)
	{
		getline(cin, c);
		int i,j,count=0;
		for(i=0; c[i]; i++)
			for(j=0; s[j]; j++)
				if(c[i]==s[j])
					count+=n[j];
		cout << "Case #" << k << ": " << count << "\n";
	}
	return 0;
}