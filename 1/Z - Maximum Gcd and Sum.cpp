/**
    "If you have an apple and I have an apple and
    we exchange apples then you and I will still
    each have one apple. But if you have an idea
    and I have an idea and we exchange these
    ideas, then each of us will have two ideas."
                        -George Bernard Shaw
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<int>a(n), b(n);
	int mx=0;
	for(int i=0; i<n; i++)
	{
		cin >> a[i];
		if(a[i]>mx)
			mx=a[i];
	}
	for(int i=0; i<n; i++)
	{
		cin >> b[i];
		if(b[i]>mx)
			mx=b[i];
	}
	vector<int>cnt(mx+1 , 0), first(mx+1, 0), second(mx+1, 0);
	for(int i=0; i<n; i++)
		cnt[a[i]]=1;
	for(int i=1; i<=mx; i++)
		for(int j=i; j<=mx; j+=i)
			if(cnt[j])
				first[i]=max(first[i], j);
	fill(cnt.begin(), cnt.end(), 0);
	for(int i=0; i<n; i++)
		cnt[b[i]]=1;
	for(int i=1; i<=mx; i++)
		for(int j=i; j<=mx; j+=i)
			if(cnt[j])
				second[i]=max(second[i], j);
	for(int i=mx; i>=0; i--)
		if(first[i] && second[i])
		{
			cout << first[i]+second[i];
			break;
		}
	return 0;
}