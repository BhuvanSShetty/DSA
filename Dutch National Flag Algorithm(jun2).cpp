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
    void sortColors(vector<int>& nums) {
        int low =0;
        int mid=0;
        int high = nums.size()-1;

        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[mid],nums[low]);
                mid++;
                low++;
                
            }
            else if(nums[mid]==1)
            {
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};

using namespace std;

int main() {
    Solution s;
    vector<int> nums = {2,0,2,1,1,0};
    s.sortColors(nums);
    for(auto num:nums)
    {
        cout<<num<<" ";
    }
    return 0;
}
/*
0 -> send left
1 -> leave it
2 -> send right

0 : low++, mid++
1 : mid++
2 : high--
*/