#include<iostream>
#include<string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s;
	int ar[4]={0};
	for(ar[0]=0; ar[0]<3; ar[0]+=2)
		for(ar[1]=0; ar[1]<3; ar[1]+=2)
			for(ar[2]=0; ar[2]<3; ar[2]+=2)
			{
				int temp=s[0]-48;
				for(int i=0; i<3; i++)
				{
					if(ar[i])
						temp-=s[i+1]-48;
					else
						temp+=s[i+1]-48;
				}
				if(temp==7)
				{
					cout << s[0];
					for(int i=0; i<3; i++)
						cout << (char)(ar[i]+43) << s[i+1];
					cout << "=7\n";
					return 0;
				}
			}
}