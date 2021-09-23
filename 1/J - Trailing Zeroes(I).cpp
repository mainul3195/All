#include<bits/stdc++.h>
using namespace std;
int num_of_occurance_in_fact(int n, int x)
{
	int count=0;
	while(n)
	{
		count+=n/x;
		n/=x;
	}
	return count;
}
int num_of_occurance_in_num(int n, int x)
{
	int count=0;
	while(!(n%x))
	{
		count++;
		n/=x;
	}
	return count;
}
int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	int i=0;
	cin >> t;
	while(t--)
	{
		int n,r,p,q;
		cin >> n >> r >> p >> q;
		int ans=min(num_of_occurance_in_fact(n,2)-num_of_occurance_in_fact(r,2)-num_of_occurance_in_fact(n-r,2)+q*num_of_occurance_in_num(p,2),num_of_occurance_in_fact(n,5)-num_of_occurance_in_fact(r,5)-num_of_occurance_in_fact(n-r,5)+q*num_of_occurance_in_num(p,5));
		cout << "Case " << ++i << ": " << ans << "\n";
	}
	return 0;
}