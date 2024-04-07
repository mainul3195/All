#include<bits/stdc++.h>
using namespace std;
int main()
{
//	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	int tc=0;
	stack<string> fr, bc;
	while(t--)
	{
		while(!fr.empty())
			fr.pop();
		while(!bc.empty())
			bc.pop();
		string cur = "http://www.lightoj.com/";
		string cmnd, vst;
		cout << "Case " << ++tc << ":\n";
		while(cin >> cmnd && cmnd != "QUIT")
		{
			if(cmnd == "VISIT")
			{
				cin >> vst;
				bc.push(cur);
				cur = vst;
				cout << cur << "\n";
				while(!fr.empty())
					fr.pop();
			}
			else if(cmnd == "BACK")
			{
				if(bc.empty())
					cout << "Ignored\n";
				else
				{
					fr.push(cur);
					cur=bc.top();
					bc.pop();
					cout << cur << "\n";
				}
			}
			else
			{
				if(fr.empty())
					cout << "Ignored\n";
				else
				{
					bc.push(cur);
					cur=fr.top();
					fr.pop();
					cout << cur << "\n";
				}

			}
		}
	}
	return 0;
}