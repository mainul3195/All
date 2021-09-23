#include<bits/stdc++.h>
using namespace std;
long long sum;
void execute(int n)
{
	if(!n)
		return ;
	int x;
	cin >> x;
	sum+=x;
	execute(n-1);
	return ;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	execute(n);
	cout << sum;
	return 0;
}