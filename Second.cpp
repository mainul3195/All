#include <bits/stdc++.h>
using namespace std;
bool leap_year(int i)
{
    return i % 400 == 0 || (i % 100 != 0 && i % 4 == 0);
}
set<int> thirty = {4, 6, 9, 11}, thirty_one = {1, 3, 5, 7, 8, 10, 12};
struct Date
{
    int year, month, day;
    void next_date()
    {
        day++;
        if (month == 2)
        {
            if ((day == 30) || (day == 29 && !leap_year(year)))
                day = 1, month++;
        }
        else
        {
            if ((thirty.find(month) != thirty.end() && day == 31) || (thirty_one.find(month) != thirty_one.end() && day == 32))
                day = 1, month++;
        }
        if (month == 13)
            month = 1, year++;
    }
    void previous_date()
    {
        day--;
        if (day == 0)
        {
            month--;
            if (month == 2)
            {
                if (leap_year(year))
                    day = 29;
                else
                    day = 28;
            }
            else if (thirty.find(month) != thirty.end())
                day = 30;
            else if (thirty_one.find(month) != thirty_one.end())
                day = 31;
            else
            {
                day = 31;
                month = 12;
                year--;
            }
        }
    }
    bool operator<(const Date &a) const
    {
        return year < a.year || (year == a.year && month < a.month) || (year == a.year && month == a.month && day < a.day);
    }
    bool operator==(const Date &a) const
    {
        return year == a.year && day == a.day && month == a.month;
    }
};
string date_to_string(Date &x)
{
    int y = x.year;
    int m = x.month;
    int d = x.day;
    string s = to_string(y);
    if (m / 10 == 0)
        s += "0";
    s += to_string(m);
    if (d / 10 == 0)
        s += "0";
    s += to_string(d);
    return s;
}
bool is_present(Date &x)
{
    string s = date_to_string(x);
    for (int i = 0; i + 2 < s.size(); i++)
        if (s.substr(i, 3) == "202")
            return true;
    return false;
}
int date[8000][13][32];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Date cur_date = {1999, 12, 31}, end_date = {9999, 12, 31}, previous_date;
    while (1)
    {
        previous_date = cur_date;
        cur_date.next_date();
        date[cur_date.year - 2000][cur_date.month][cur_date.day] = date[previous_date.year - 2000][previous_date.month][previous_date.day] + is_present(cur_date);
        if (cur_date == end_date)
            break;
    }
    int n;
    cin >> n;
    while (n--)
    {
        Date starting_date, ending_date;
        cin >> starting_date.year >> starting_date.month >> starting_date.day >> ending_date.year >> ending_date.month >> ending_date.day;
        starting_date.previous_date();
        cout << date[ending_date.year - 2000][ending_date.month][ending_date.day] - date[starting_date.year - 2000][starting_date.month][starting_date.day] << "\n";
    }

    return 0;
}

/*
Summary:
Given a starting and a ending date. You have to find the number of dates in the range such that
the date converted in the string format "YYYYMMDD" has substring "202" in it.
For Example, "21110202" has "202" as a substring.


Editorial:
This problem is of catagory basic observation and implementation.
If we observe carefully, we can see that there will be at most 3,000,000 number of different dates
in the given range. So if we can store them serially, we will be able to use cumulative sum method
to answer each query in O(1) time complexity.
The easiest way to implement this is to maintain a three dimentional array where the first dimention
day, second dimention is month and the third dimention is year.
Then we have to implement how to propagate through dates, in other words, how to find next date. We can
do this using appropriates function or inside a manually made structure Date as a utility function.

After doing all this, we have to find the cumulative sum array which is a three dimentional array.
If the current date contains "202" as a substring, we can update the cumulative array (date in this solution)
like this: date[cur_y][cur_m][cur_d] = date[prev_y][prev_d][prev_m] + is_present(cur)
Here cur represents current date, prev represents previous date and is_present is a fuction which returns 0 or 1
on the basis of presense of string "202" as a substring of current date.

Now we have successfully made our cumulative sum array. At this point we can simply answer the queries by substracting
the cumulative value of previous day of the starting date from the ending date.


*/