#include<bits/stdc++.h>
using namespace std;
void execute();
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	while(n--)
		execute();
	return 0;
}
void execute()
{
	int n,i;
	cin>>n;
	for(i=0; i<n; i++)
		cout << "2" << " \n"[i==n-1];
	return;
}