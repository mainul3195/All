#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s;
	int no0=0;
	for(int i=0; i<s.size(); i++)
		if(s[i]=='0')
			no0++;
	int x=s.size()-no0;
	cout << min(no0, (int)(s.size()-no0)) ;
	return 0;
}