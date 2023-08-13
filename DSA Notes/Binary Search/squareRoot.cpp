#include <bits/stdc++.h>
using namespace std;
int sqrt(int x) {
    int s = 1;
    int e = x;

    while (s <= e) {
        long long int mid = s + (e - s) / 2;
        if (mid * mid == x) {
            return mid;
        } else if (mid * mid > x) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return e;
}

int main() {
    int number = 28;
    cout << sqrt(number) << endl;
}