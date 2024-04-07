#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int w,h;
    int x[]={1,0,-1,0},y[]={0,-1,0,1};
    cin >> h >> w;
    vector<string> s(h);
    for(int i=0; i<h;  i++)
        cin >> s[i];
    bool ok=1;
    for(int i=0; i<h; i++)
        if(ok)
        for(int j=0; j<w; j++)
            if(s[i][j]=='#')
            {
                int k;
                for(k=0; k<4; k++)
                {
                    int u=i+x[k];
                    int v=j+y[k];
                    if(u>=0 && u<h && v>=0 && v<w && s[u][v]=='#')
                        break;
                }
                if(k==4)
                {
                    ok=0;
                    break;
                }
            }
    if(ok)
        cout << "Yes\n";
    else 
        cout << "No\n";
    return 0;
}