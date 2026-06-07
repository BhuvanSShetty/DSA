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
    vector<int> findMissingRepeatingNumbers(vector<int>& nums) {

        int n = nums.size();

        long long xr = 0;

        // XOR array and 1..n
        for(int i = 0; i < n; i++) {
            xr ^= nums[i];
            xr ^= (i + 1);
        }

        // rightmost set bit
        long long bit = xr & (-xr);

        long long zero = 0;
        long long one = 0;

        // divide into 2 groups
        for(int i = 0; i < n; i++) {

            if(nums[i] & bit)
                one ^= nums[i];
            else
                zero ^= nums[i];

            if((i + 1) & bit)
                one ^= (i + 1);
            else
                zero ^= (i + 1);
        }

        // identify repeating number
        int cnt = 0;

        for(int x : nums) {
            if(x == one)
                cnt++;
        }

        if(cnt == 2)
            return {(int)one, (int)zero};

        return {(int)zero, (int)one};
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 1, 2, 5, 3};
    vector<int> ans = s.findMissingRepeatingNumbers(nums);
    cout << "Repeating Number: " << ans[0] << ", Missing Number: " << ans[1] << endl;       

    return 0;
}