#include <bits/stdc++.h>
using namespace std;
int searchRotatedSorted(vector<int> nums, int target) {
    int s = 0, e = nums.size() - 1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (nums[mid] == target) {
            return mid;
            // left sorted condition
        } else if (nums[s] <= nums[mid]) {
            if (target >= nums[s] && target < nums[mid]) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        //right sorted condition
        } else {
            if (nums[mid]<target&&nums[e]>=target) {
            s=mid+1;
            } else {
            e=mid-1;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {3,1};
    cout << searchRotatedSorted(nums, 1)<<endl;
}