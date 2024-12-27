#include<bits/stdc++.h>

using namespace std;

/*
Find the index of the goal using binary search.
If the goal is not in nums, find the closest number.
Example 1
     nums = {1,2,3,7} goal = 4
     bs(nums,goal) == 2

Example 2
     nums = {1,4,6} goal = 4
     bs(nums,goal) == 1

Example 3
     nums = {-1,1,2,5} goal = 4
     bs(nums,goal) == 3
*/
int bs(vector<int>& nums, int goal) {
    int n = nums.size();
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == goal)
            return mid;
        else if (nums[mid] < goal)
            left = mid + 1;
        else
            right = mid - 1;
    }
    if (right < 0)
        return left;
    if (left < n && abs(nums[left] - goal) < abs(nums[right] - goal))
        return left;
    return right;
}