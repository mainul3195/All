#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	char s[]="GBIV";
	int n, i;
	cin >> n;
	n-=3;
	cout << "ROY";
	for(i=0; i<n; i++)
		cout << s[i%4];
	return 0;
}