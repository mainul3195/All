#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
void solve()
{
    string a, b, c;
    cin >> a >> b >> c;
    if ((mp[b] - mp[a] + 12) % 12 == 4 && (mp[c] - mp[b] + 12) % 12 == 3)
        cout << "Major triad\n";
    else if ((mp[b] - mp[a] + 12) % 12 == 3 && (mp[c] - mp[b] + 12) % 12 == 4)
        cout << "Minor triad\n";
    else
        cout << "Dissonance\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    mp["C"] = 0;
    mp["C#"] = 1;
    mp["D"] = 2;
    mp["D#"] = 3;
    mp["E"] = 4;
    mp["F"] = 5;
    mp["F#"] = 6;
    mp["G"] = 7;
    mp["G#"] = 8;
    mp["A"] = 9;
    mp["A#"] = 10;
    mp["B"] = 11;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}