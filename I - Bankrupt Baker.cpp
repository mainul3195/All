#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	//getchar();

	while(t--)
	{
		string s;
		getline(cin , s);
		string binder_name;
		getline(cin, binder_name);
		for(int i=0; binder_name[i]; i++)
			binder_name[i]=toupper(binder_name[i]);
		cout << binder_name << "\n";
		int m,n,b;
		cin >> m >> n >> b;
		map<string, int> ingr,recipe;
		while(m--)
		{
			int i;
			cin >> s >> i;
			ingr[s]=i;
		}
		while(n--)
		{
			getline(cin , s);
			getline(cin , s);
			//cout << s << "\n";
			recipe[s]=0;
			int i,j;
			cin >> i;
			string name;
			while(i--)
			{
				cin >> name >> j;
				recipe[s]+= ingr[name]*j;
			}
		}
		// for(auto it=recipe.begin(); it!=recipe.end(); ++it)
		// 	if(it->second>b)
		// 		recipe.erase(it->first);
		vector<pair<int, string> > v;
		pair<int, string> p;
		for(auto it=recipe.begin(); it!=recipe.end(); ++it)
		{
			p={it->second, it->first};
			v.push_back(p);
		}
		for(int i=0; i<v.size(); i++)
			if(v[i].first>b)
			{
				v.erase(v.begin()+i);
				i--;
			}
		sort(v.begin(), v.end());
		if(v.empty())
			cout << "Too expensive!\n";
		else
		{
			for(int i=0; i<v.size(); i++)
				cout << v[i].second << "\n";
		}
		cout << "\n";
		s.clear();
		binder_name.clear();
		recipe.clear();
		ingr.clear();
	}
	return 0;
}