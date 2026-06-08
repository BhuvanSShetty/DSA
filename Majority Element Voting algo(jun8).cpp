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
    int majorityElement(vector<int>& nums) {

        int cnt = 0;
        int candidate = 0;

        for(int x : nums)
        {
            if(cnt == 0)
                candidate = x;

            if(x == candidate)
                cnt++;
            else
                cnt--;
        }

        return candidate;
    }
};

int main() {

    Solution s;
    vector<int> nums = {2,2,1,1,1,2,2};
    int majority = s.majorityElement(nums);
    cout << "Majority Element: " << majority << endl;
    
    return 0;
}