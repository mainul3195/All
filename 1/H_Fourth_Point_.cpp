#include<bits/stdc++.h>
using namespace std;
#define mn 1e-7
struct nd
{
    long double x, y;
    bool operator==(const nd &a)
    {
        if(fabs(x-a.x)<mn && fabs(y-a.y)<mn)
            return 1;
        return 0;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long double a, b, c, d, e, f, g, h;
    while(cin >> a >> b >> c >> d >> e >> f >> g >> h)
    {
        nd p[4], tp[3];
        p[0] = {a, b};
        p[1] = {c, d};
        p[2] = {e, f};
        p[3] = {g, h};
        int sm1, sm2;
        for (int i = 0; i < 3; i++)
            for (int j = i + 1; j < 4; j++)
                if(p[i]==p[j])
                {
                    sm1 = i;
                    sm2 = j;
                    tp[2] = p[i];
                    break;
                }
        int st = 0;
        for (int i = 0; i < 4; i++)
            if(i != sm1 && i != sm2)
                tp[st++] = p[i];
        cout << fixed << setprecision(3) << tp[0].x + tp[1].x - tp[2].x << " " << tp[0].y + tp[1].y - tp[2].y << "\n";
    }
    return 0;
}