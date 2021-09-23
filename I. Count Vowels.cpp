#include<bits/stdc++.h>
using namespace std;
int c;
string s;
void print(int n)
{
	if(!s[n])
		return;
	if(s[n]=='u' ||s[n]=='o' ||s[n]=='i' ||s[n]=='e' ||s[n]=='a' ||s[n]=='U' ||s[n]=='O' ||s[n]=='I' ||s[n]=='E' ||s[n]=='A')
		c++;
	print(n+1);
	return;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	getline(cin, s);
	print(0);
	cout << c;
	return 0;
}