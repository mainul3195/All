#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("lights.in", "r", stdin);
    // freopen("lights.out", "w", stdout);
    int a, b, x;
    cin >> a >> b >> x;
    double required_time = x / 1000.0;
    int floor_value = (required_time + 1e-15);
    int prev_limit = floor_value / (a + b) * (a + b) + a;
    int next_limit = (floor_value + a + b - 1) / (a + b) * (a + b) - a;
    if (prev_limit >= next_limit)
        cout << fixed << setprecision(10) << 1000.0 << "\n";
    else
    {
        if (required_time - 1e-15 > prev_limit && required_time + 1e-15 < next_limit)
            cout << fixed << setprecision(10) << (double)x / next_limit << "\n";
        else
            cout << fixed << setprecision(10) << 1000.0 << "\n";
    }
    return 0;
}

/*
Summary:

There are two street lights located at a distance x miles. Each light changes its color to only green and red simultaneously. The green light lasts long for a second and the red light lasts for b seconds. You want to cross two street lights at a constant speed with a car that has a maximum speed of 1000 miles/second. You can cross the street lights only when they are green or at the very moment when they are changing color. Now, what is the maximum constant speed you can gain to successfully cross the lights with the appropriate condition?


Editorial:

The problem is mainly the observation category.
If the green color changes after each 'a' second and the red color changes after each 'b' second, we can list the permitted time for us we can use to cross the lights, they are:
0 to a, (a+b)-a to (a+b) + a, 2*(a+b)-a to 2*(a+b)+a, 3*(a+b)-a to 3*(a+b)+a, ....
In general, the time we can use to cross the lights is between k*(a+b)-a to k*(a+b)+a for any non-negative value of k excluding the non-positive time.
Now, at first, we will try to maintain our maximum available speed available which is 1000 miles/second. We will calculate our required time for this. Using the required speed, we will calculate the value of k, for which, our required time falls into the range (k-1)*(a+b) to k*(a+b). Then we calculate the two terminal limits of permitted times,
previous limit = (k-1)*(a+b)+a
last limit = k*(a+b)-a
If our required time is less than or equal to the previous limit or greater than or equal to the last limit, we can use our maximum permitted limit. But if our required time falls into the non-permitted region, we have to use the next permitted time, that is the last limit. So, our maximum speed will be x/last_limit.
*/