#include <bits/stdc++.h>
using namespace std;
struct nd
{
    double xl, yl, xu, yu, z;
};
struct seg
{
    double x, low, high;
};
double find_x_intersect(double x1, double y1, double x2, double y2)
{
    return x1 - y1 * ((x1 - x2) / (y1 - y2));
}
double find_max_distance_intersect(double x1, double y1, double x2, double y2, double y)
{
    return x1 + (y - y1) * ((x1 - x2) / (y1 - y2));
}
bool intersects_all(double x1, double y1, double x2, double y2, vector<seg> &segments)
{
    for (auto [z, l, h] : segments)
    {
        double a1 = x2 - x1;
        double b1 = y2 - y1;
        double a2 = l - x1;
        double b2 = z - y1;
        double a3 = h - x1;
        double b3 = z - y1;
        if ((a1 * b2 - b1 * a2) * (a1 * b3 - b1 * a3) + 1e-15 > 0 && fabs((a1 * b2 - b1 * a2) * (a1 * b3 - b1 * a3) - 0) > 1e-10)
            return false;
    }
    return true;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("gunman.in", "r", stdin);
    // freopen("gunman.out", "w", stdout);
    int n;
    cin >> n;
    vector<nd> windows(n);
    for (auto &[a, b, c, d, e] : windows)
        cin >> a >> b >> c >> d >> e;
    vector<seg> z_vs_x, y_vs_z;
    for (auto [xl, yl, xu, yu, z] : windows)
    {
        z_vs_x.push_back({z, xl, xu});
        y_vs_z.push_back({z, yl, yu});
    }
    // Checking if we can shoot from X axis
    double amx = -1, amn = (double)y_vs_z[0].high / y_vs_z[0].x;
    for (auto [z, l, h] : y_vs_z)
    {
        amx = max(amx, (double)l / z);
        amn = min(amn, (double)h / z);
    }
    if (amx > amn && fabs(amx - amn) > 1e-9)
    {
        cout << "UNSOLVABLE\n";
        return 0;
    }

    // Solving for upper view: z_vs_x graph
    double shooting_point_min = 1000000000, shooting_point_max = -1000000000, farthest_min = 1000000000, farthest_max = -1000000000;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            double x_intersect, farthest_point_intersect;
            if (intersects_all(z_vs_x[i].low, z_vs_x[i].x, z_vs_x[j].low, z_vs_x[j].x, z_vs_x))
            {
                x_intersect = find_x_intersect(z_vs_x[i].low, z_vs_x[i].x, z_vs_x[j].low, z_vs_x[j].x);
                farthest_point_intersect = find_max_distance_intersect(z_vs_x[i].low, z_vs_x[i].x, z_vs_x[j].low, z_vs_x[j].x, windows[n - 1].z);
                shooting_point_max = max(shooting_point_max, x_intersect);
                shooting_point_min = min(shooting_point_min, x_intersect);
                farthest_max = max(farthest_max, farthest_point_intersect);
                farthest_min = min(farthest_min, farthest_point_intersect);
            }
            if (intersects_all(z_vs_x[i].low, z_vs_x[i].x, z_vs_x[j].high, z_vs_x[j].x, z_vs_x))
            {
                x_intersect = find_x_intersect(z_vs_x[i].low, z_vs_x[i].x, z_vs_x[j].high, z_vs_x[j].x);
                farthest_point_intersect = find_max_distance_intersect(z_vs_x[i].low, z_vs_x[i].x, z_vs_x[j].high, z_vs_x[j].x, windows[n - 1].z);
                shooting_point_max = max(shooting_point_max, x_intersect);
                shooting_point_min = min(shooting_point_min, x_intersect);
                farthest_max = max(farthest_max, farthest_point_intersect);
                farthest_min = min(farthest_min, farthest_point_intersect);
            }
            if (intersects_all(z_vs_x[i].high, z_vs_x[i].x, z_vs_x[j].low, z_vs_x[j].x, z_vs_x))
            {
                x_intersect = find_x_intersect(z_vs_x[i].high, z_vs_x[i].x, z_vs_x[j].low, z_vs_x[j].x);
                farthest_point_intersect = find_max_distance_intersect(z_vs_x[i].high, z_vs_x[i].x, z_vs_x[j].low, z_vs_x[j].x, windows[n - 1].z);
                shooting_point_max = max(shooting_point_max, x_intersect);
                shooting_point_min = min(shooting_point_min, x_intersect);
                farthest_max = max(farthest_max, farthest_point_intersect);
                farthest_min = min(farthest_min, farthest_point_intersect);
            }
            if (intersects_all(z_vs_x[i].high, z_vs_x[i].x, z_vs_x[j].high, z_vs_x[j].x, z_vs_x))
            {
                x_intersect = find_x_intersect(z_vs_x[i].high, z_vs_x[i].x, z_vs_x[j].high, z_vs_x[j].x);
                farthest_point_intersect = find_max_distance_intersect(z_vs_x[i].high, z_vs_x[i].x, z_vs_x[j].high, z_vs_x[j].x, windows[n - 1].z);
                shooting_point_max = max(shooting_point_max, x_intersect);
                shooting_point_min = min(shooting_point_min, x_intersect);
                farthest_max = max(farthest_max, farthest_point_intersect);
                farthest_min = min(farthest_min, farthest_point_intersect);
            }
        }
    if (fabs(shooting_point_min - 1000000000) < 1e-9)
    {
        cout << "UNSOLVABLE\n";
        return 0;
    }
    cout << "SOLUTION\n";
    double slope_for_y_vs_z = (amn + amx) / 2;
    double shooting_point = (shooting_point_max + shooting_point_min) / 2;
    double farthest = (farthest_max + farthest_min) / 2;
    cout << fixed << setprecision(6) << shooting_point << "\n";
    for (int i = 0; i < n; i++)
    {
        double x1 = shooting_point, x2 = farthest, y2 = windows[n - 1].z;
        cout << fixed << setprecision(6) << (x1 - windows[i].z * ((x1 - x2) / y2)) << " " << slope_for_y_vs_z * windows[i].z << " " << windows[i].z << "\n";
    }
    return 0;
}