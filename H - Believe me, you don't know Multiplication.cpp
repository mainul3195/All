#include<bits/stdc++.h>
using namespace std;
string add(string a, string b)
{
	int l1=a.size(), l2=b.size();
	int l=max(l1,l2),car=0;
	string s;
	char t[3]={0};
	for(int i=0; i<l || car; i++)
	{
		int s1=0,s2=0;
		if(i<l1)
			s1=a[i]-48;
		if(i<l2)
			s2=b[i]-48;
		int sum=s1+s2+car;
		car=sum/10;
		char c=sum%10 + 48;
		t[0]=c;
		s.insert(i, t);
	}
	return s;
}
string subt(string a, string b)
{
	int l1=a.size(), l2=b.size();
	int l=max(l1,l2),car=0;
	string s;
	char t[3]={0};
	for(int i=0; i<l || car; i++)
	{
		int s1=0,s2=0;
		s1=a[i]-48;
		if(i<l2)
			s2=b[i]-48;
		if(s1<s2)
			s1+=10;
		int sum=s1-s2+car;
		char c=sum%10 + 48;
		t[0]=c;
		s.insert(i, t);
		if(s1<s2)
			car=1;
		else
			car=0;
	}
	return s;
}
string karatsuba(string a, string b)
{
	if(a[0]=='0' && a[1]==0 || b[0]=='0'&&b[1]==0)
		return "0\0";
	if(a[1]==0 && b[1]==0)
	{
		char s[3];
		s[0]=(a[0]-48 + b[0]-48)%10;
		if((a[0]-48 + b[0]-48)/10)
		{
			s[1]=(a[0]-48 + b[0]-48)/10;
			s[2]=0;
		}
		else
			s[1]=0;
		return s;
	}
	int l=0,l1=0,mx,i;
	char s[3]={0};
	l=a.size();
	l1=b.size();
	mx=max(l,l1);
	if(mx%2)
		mx++;
	string x1,x2,y1,y2,s1,s2,s3;
	for(i=0; i<mx/2 && i<l; i++)
	{
		s[0]=a[i];
		x2.insert(i, s);
	}
	for(;i<mx/2; i++)
	{
		s[0]='0';
		x2.insert(i, s);
	}
	int j=0;
	for(; i<l; i++)
	{
		s[0]=a[i];
		x1.insert(j++,s);
	}
	for(; i<mx; i++)
	{
		s[0]='0';
		x1.insert(j++, s);
	}

	for(i=0; i<mx/2 && i<l1; i++)
	{
		s[0]=b[i];
		y2.insert(i, s);
	}
	for(;i<mx/2; i++)
	{
		s[0]='0';
		y2.insert(i, s);
	}
	j=0;
	for(; i<l1; i++)
	{
		s[0]=b[i];
		y1.insert(j++,s);
	}
	for(; i<mx; i++)
	{
		s[0]='0';
		y1.insert(j++, s);
	}
	s1=karatsuba(x1,y1);
	s2=karatsuba(x2,y2);
	s3=subt(karatsuba(add(x1,x2),add(y1,y2)),add(s1,s2));
	int len=s1.size();
	for(i=0; i<mx; i++)
	{
		s[0]='0';
		s1.insert(len++,s);
	}
	len=s3.size();
	for(i=0; i<mx; i++)
	{
		s[0]='0';
		s3.insert(len++,s);
	}
	return add(add(s1,s2), s3);
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		string a,b;
		cin >> a >> b;
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		cout << subt(a,b) << "\n";
	}
	return 0;
}