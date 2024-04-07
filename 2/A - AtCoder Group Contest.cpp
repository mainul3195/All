#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(int a, int b) {return a>b;}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n ;
	int i;
	vector<int> v(3*n);
	for(int i=0; i<3*n; i++)
		cin >> v[i];
	sort(v.begin(), v.end(), cmp);
	long long ans=0;
	for(int i=1; i/2<n ; i+=2)
		ans+=v[i];
	cout << ans << "\n";
	return 0;
}