#include<bits/stdc++.h>
using namespace std;
string a, b;
bool hoyeche(int i, int j, int dir)
{
    if(j==b.size())
        return true;
    bool ok1, ok2;
    ok1 = ok2 = false;
    if(dir && i+1<a.size() && a[i+1]==b[j])
        ok1 = hoyeche(i+1, j+1, 1);
    if(!ok1 && i>0 && a[i-1]==b[j])
        ok2 = hoyeche(i-1, j+1, 0);
    return ok1||ok2;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        bool ok = 0;
        for(int i=0; i<a.size(); i++)
            if(a[i]==b[0] && hoyeche(i,1,1))
            {
                ok = 1;
                break;
            }
        if(ok)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}