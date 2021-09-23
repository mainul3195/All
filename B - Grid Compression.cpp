#include<iostream>
#include<vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    vector<int> row(h,1), col(w,1);
    for(int i=0; i<h; i++)
        cin >> s[i];
    for(int i=0; i<h; i++)
    {
        int count=0;
        for(int j=0; j<w; j++)
            if(s[i][j] == '#')
                count++;
        if(!count)
            row[i]=0;
    }
    for(int i=0; i<w; i++)
    {
        int count=0;
        for(int j=0; j<h; j++)
            if(s[j][i] == '#')
                count++;
        if(!count)
            col[i]=0;
    }
    for(int i=0; i<h; i++)   
    {
        if(!row[i])
            continue;
        for(int j=0; j<w; j++)
        {
            if(!col[j])
                continue;
            cout << s[i][j];
        }
        cout << "\n";
    }
    return 0;
}