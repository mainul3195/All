#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<int> num(n),longestsequence(n);
	for(int i=0; i<n; i++)
		cin >> num[i];
	longestsequence[0]=1;
	for(int i=1; i<n ;i++)
	{
		if(__gcd(num[i], num[i-1])>1 || (i>1 && __gcd(num[i], num[i-2])>1))
			longestsequence[i]=longestsequence[i-1]+1;
		else
			longestsequence[i]=longestsequence[i-1];
	}
	cout << longestsequence[n-1] << "\n";
	return 0;
}