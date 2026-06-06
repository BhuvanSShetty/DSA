#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <climits>
#include <cmath>
#include <numeric>
#include <deque>

using namespace std;


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);

        slow = nums[0];

        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }

        return slow;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,3,4,2,2};
    int duplicate = s.findDuplicate(nums);
    cout << "Duplicate Number: " << duplicate << endl;
    return 0;
}