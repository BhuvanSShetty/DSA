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

class Solution
{
    public:

    void nextPermuation(vector<int>& nums)
    {
        int n = nums.size();

        int i = n-2;

        while(i>=0 && nums[i]>=nums[i+1])
        {
            i--;
        }
        
        if(i>=0)
        {
            int j =n-1;
            while(nums[j]<=nums[i])
            {
                j--;
            }
            swap(nums[j],nums[i]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    
    }


};

int main() {
    Solution s;
    vector<int> nums = {1,2,3,4};
    s.nextPermuation(nums);
    for(auto num:nums)
    {
        cout<< num <<" ";
    }
    return 0;
}