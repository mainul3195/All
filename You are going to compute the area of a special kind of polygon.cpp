#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x[15]={0,-1,0,1,-1,0,1,-1,0,1},y[15]={0,-1,-1,-1,0,0,0,1,1,1};
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        long long cx=0, cy=0;
        long long area=0;
        long long prevx=0, prevy=0;
        for(int i=0; i<s.size(); i++)
        {
            int ind=s[i]-48;
            cx+=x[ind];
            cy+=y[ind];
            area += prevx*cy-prevy*cx;
            prevx=cx;
            prevy=cy;
        }
        if(area<0)
            area = -area;
        cout << area/2;
        if(area%2)
            cout << ".5\n";
        else 
            cout << "\n";
    }
    return 0;
}
