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
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt =0;
        int max1 =0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
                cnt++;
            else
                cnt=0;
            max1=max(max1,cnt);
        }
        return max1;
    }
};
int main() {
    Solution s;
    vector<int> nums = {1,1,0,1,1,1};
    int cnt = s.findMaxConsecutiveOnes(nums);
    cout<<"Count of largest sub string is"<< cnt;
    

    return 0;
}