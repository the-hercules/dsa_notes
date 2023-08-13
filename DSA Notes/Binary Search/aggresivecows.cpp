#include <bits/stdc++.h>
using namespace std;

int canWePlace(vector<int> stalls, int mid, int k) {
    int cowCount = 1;
    int cowCoordinate = stalls[0];
    // first wale se just aage wale coordinate se dekhna shuru karo
    // ki distance ka scene sahi gap per beth raha hai ki nahi
    // like agar minimum distance abhi 2 chal raha hai to
    // dekhte chalo bc har ek ke sath ki possible hai ki nahi
    // tab hee to possible solution niklega
    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - cowCoordinate>=mid){
            cowCount++;
            cowCoordinate=stalls[i];
        }
    }
    if(cowCount>=k){
        return true;
    }
    else{
        return false;
    }
}

int aggressiveCows(vector<int> stalls, int k) {
    // sort the vector
    sort(stalls.begin(), stalls.end());
    int s = 0;
    int e = stalls.back() - stalls.front();
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (canWePlace(stalls, mid, k)) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return e;
}

int main() {
    vector<int> stalls = {4, 2, 1, 3, 6 };
    int k = 4;
    int ans = aggressiveCows(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    return 0;
}
