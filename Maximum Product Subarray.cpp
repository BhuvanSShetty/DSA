#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxnum=nums[0], minnum=nums[0] , result=nums[0];
        for(int i=1 ; i<nums.size();i++)
        {
            int num= nums[i];
            if(num<0)
                swap(maxnum,minnum);
            maxnum = max(num,maxnum*num);
            minnum = min(num,minnum*num);
            result = max(result,maxnum);
        }

        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2,3,-2,4};
    int result = s.maxProduct(nums);
    cout << "Maximum Product: " << result << endl;
    return 0;
}