#include <iostream>
using namespace std;

int l, r, b, k;

bool can_kill_geese(long long wait_time) {
    long long next_goose_time = 0;
    int num_geese_killed = 0;
    while (num_geese_killed < k) {
        if (next_goose_time <= wait_time) {
            // Kill the goose
            num_geese_killed++;
            next_goose_time += b;
        } else {
            // Wait for killing skill to cool down
            next_goose_time -= wait_time;
        }
        if (next_goose_time > k * b) {
            // Unable to kill k geese within given wait_time
            return false;
        }
    }
    // Able to kill k geese within given wait_time
    return true;
}

int main() {
    cin >> l >> r >> b >> k;

    long long left = l, right = r;
    while (left < right) {
        long long mid = (left + right) / 2;
        if (can_kill_geese(mid)) {
            // Able to kill k geese within mid seconds
            right = mid;
        } else {
            // Unable to kill k geese within mid seconds
            left = mid + 1;
        }
    }
    cout << left << endl;

    return 0;
}
