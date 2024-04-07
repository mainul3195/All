#include <bits/stdc++.h>
using namespace std;
void execute();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        execute();
    return 0;
}
void execute()
{
	int n;
	cin >> n;
	n=(n+1)/2;
	cout << n << "\n";
    return;
}