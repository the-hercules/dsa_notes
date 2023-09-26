#include "bits/stdc++.h"
using namespace std;
int min_circular_distance(int a, int b) {
    int diff = abs(a - b);
    return min(diff, 10 - diff);
}


int main() {
cout<<min_circular_distance(8,2);
}
