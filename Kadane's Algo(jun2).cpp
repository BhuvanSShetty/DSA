
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
    int maxSubArray(vector<int>& nums) {
        int curr = nums[0];
        int maxsum = nums[0];

        for(int i=1;i<nums.size();i++)
        {
            curr = max(nums[i],curr+nums[i]);
            maxsum = max(maxsum,curr);
        }
        return maxsum;
    }
};

int main() {
    Solution s;
    vector<int> ans ={-2,1,-3,4,-1,2,1,-5,4};
    int anss = s.maxSubArray(ans);
    cout<<anss;
    return 0;
}

/*Kadane:

curr -> max subarray ending at i
maxsum -> answer

At every index:
1. Continue old subarray
2. Start new subarray

Take whichever gives bigger sum.
*/