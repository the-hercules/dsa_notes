#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int main() {
    vector<int> a = {1, 2, 3, 4};
    vector<int> b;
    b.insert(b.begin(), a.begin(), a.end());
    for (auto i : b) {
        cout << i << " " << endl;
    }
}