#include<iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	long long k;
	cin >> s >> k;
	int i;
	bool ok=0;
	for( i=0; i<k && i<s.size(); i++)
		{
			if(s[i]=='1')
				continue;
			cout << s[i];
			ok=1;
			break;
		}
	if(!ok)
		cout << s[k-1];
	return 0;
}