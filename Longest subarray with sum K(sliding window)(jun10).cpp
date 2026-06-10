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
class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        int left=0;
        int ans=0;
        int cnt=0;
        for(int right = 0; right<nums.size();right++)
        {   
            ans+=nums[right];
            while(ans>k)
            {
                ans-=nums[left];
                left++;
            }
            
            if(ans==k)
            {
                cnt=max(cnt,right-left+1);
            }

        }
        return cnt;
    }
};


int main() {
    Solution s;
    vector<int> nums = {1, 1, 0, 1, 1, 0, 1};
    int k = 3;
    int longest = s.longestSubarray(nums, k);
    cout << "Length of the longest subarray with sum " << k << ": " <<  longest << endl;
    return 0;
}