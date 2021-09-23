#include<bits/stdc++.h>
using namespace std;
#define ckbit(x) (t[(x)/64] & 1 << ((x)%64)/2)
#define cngbit(x) (t[(x)/64] |= 1 << ((x)%64)/2)
int t[20];
vector<int> v;
void sieve()
{
	v.push_back(2);
	for(int i=3; i<32; i+=2)
		if(!ckbit(i))
			for(int j=i*i; j<=1000; j+=2*i)
				cngbit(j);
	for(int i=3; i<=1000; i+=2)
		if(!ckbit(i))
			v.push_back(i);
}
int find(int n)
{
	int l=0, r=v.size()-1, mid, ans;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(v[mid]<=n)
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
	sieve();
	int n,k;
	cin >> n >> k;
	int count=0;
	for(int i=4; v[i]<=n; i++)
	{
		int ind=find((v[i]-1)/2);
		if(v[ind]+v[ind+1]==v[i]-1)
			count++;
	}
	//cout << count << "\n";
	if(count >= k)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}