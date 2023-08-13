#include <bits/stdc++.h>
using namespace std;
bool search(vector<int>& nums, int target) {
    int s=0,e=nums.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
                return true;
            }
            //very important,
            //very important.
            //we shrink the array if array is like [1,0,1,1,1]
            if(nums[s] == nums[mid] and nums[mid] == nums[e])
            {
                s++; e--;
                continue;
            }
            //left sorted
           if(nums[s]<=nums[mid]){
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
    return false;
}

int main() {
    vector<int> nums = {3, 1};
    cout << search(nums, 1) << endl;
}