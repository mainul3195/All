#include<bits/stdc++.h>
using namespace std;
int zeroes(int n)
{
	int count=0;
	while(n)
	{
		count+=n/5;
		n/=5;
	}
	return count;
}
int uplim(int n)
{
	int l=5, r=500010, mid, ans=0;
	while(l<=r)
	{
		mid=(l+r)/2;
		int count=zeroes(mid);
		if(count>n)
		{
			ans=mid;
			r=mid-1;
		}
		else
			l=mid+1;
	}
	return ans;
}
int downlim(int n)
{
	int l=4, r=500010, mid, ans=0;
	while(l<=r)
	{
		mid=(l+r)/2;
		int count=zeroes(mid);
		if(count<n)
		{
			ans=mid;
			l=mid+1;
		}
		else
			r=mid-1;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	int up=uplim(n);
	int down=downlim(n);
	//cout << up << " " << down << "\n";
	if(zeroes(up-1)==n && zeroes(down+1)==n)
	{
		cout << up-down-1 << "\n";
		for(int i=down+1; i<up; i++)
			cout << i << " \n"[i==up-1];
	}
	else
		cout << "0\n";
	return 0;
}