#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	string s;
	int ck[27]={0};
	int flag=1;
	for(int i=0; i<n; i++)
	{
		cin >> s;
		for(char c:s)
		{
			if(!ck[c-97])
				ck[c-97]=flag;
			else if(ck[c-97]!=flag)
			{
				int temp=ck[c-97];
				for(int k=0; k<27; k++)
					if(ck[k]==temp)
						ck[k]=flag;
			}
		}
		flag++;
	}
	// for(int i=0; i<4; i++)
	// 	cout << ck[i] ;
	// cout << "\n";
	set<int> st;
	for(int i=0; i<27; i++)
		if(ck[i])
		st.insert(ck[i]);
	cout << st.size() << "\n";
	return 0;
}